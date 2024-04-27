//============================================================================
// Name        : Device.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================
#include <iostream>
#include <algorithm>
#include "Device.h"
#include "XMLREADER/XMLReader.h"

using namespace std;

Device::Device(const string &name, int emissions, const string &deviceType, int speed, int cost_per_page, int accumulatedPages)
        : deviceName(name), emissions(emissions), deviceType(deviceType), speed(speed), cost_per_page(cost_per_page), accumulatedPages(accumulatedPages){}

// Static member function to populate devices from XMLReader
vector<Device> Device::devices;
vector<Device> Device::populateFromXMLReader(const XMLReader& xmlReader) {
    // Access vectors from XMLReader
    const vector<DeviceInfo>& deviceInfoList = xmlReader.getDeviceInfoList();
    // Clear any existing devices before populating new ones.
    devices.clear();

    // Populate Device objects using data from deviceInfoList vector
    for (const auto& deviceInfo : deviceInfoList) {
        Device device(deviceInfo.deviceName, deviceInfo.emissions, deviceInfo.deviceType, deviceInfo.speed, deviceInfo.costpp);
        devices.push_back(device);
    }
    return devices;
}
// This is a function use to print each one of the contents in the list of Devices.
void Device::printDeviceInfo() const {
    if (logerrors) cout << "Device Name: " << deviceName << endl;
    if (logerrors) cout << "Emissions: " << emissions << endl;
    if (logerrors) cout << "Type: " << deviceType << endl;
    if (logerrors) cout << "Speed: " << speed << endl;
    if (logerrors) cout << "Cost per page: " << cost_per_page << endl;
}
DeviceInfo Device::giveDeviceInfo() const {
    DeviceInfo info;
    info.deviceName = deviceName;
    info.emissions = emissions;
    info.deviceType = deviceType;
    info.speed = speed;
    info.costpp = cost_per_page;
    info.accumulatedPages = accumulatedPages;
    return info;
}
vector<vector<pair<string, vector<Job>>>> Device::processedJobsVector;
bool Device::manualProcess(const DeviceInfo& selectedDevice, JobInfo& job){
    JobInfo jobInfo = job;
    DeviceInfo selectedDeviceInfo = selectedDevice;
    jobInfo.totalCost = jobInfo.pageCount * selectedDeviceInfo.costpp;
    Job job2(jobInfo.jobNumber, jobInfo.pageCount, jobInfo.jobType, jobInfo.userName, jobInfo.totalCost);
    if (jobInfo.jobType == "bw" or jobInfo.jobType == "color") {
        int pageCount = jobInfo.pageCount; // Access pageCount directly from jobInfo
        // Process the first job in the job list
        int printedPages = 0;
        if (logerrors) cout << "Starting the printing process..." << endl;
        while (printedPages < pageCount) {
            ++printedPages; // Increment printed pages
            if (logerrors) cout << "Printed pages: " << printedPages << endl;
            // Check if all pages have been printed
            if (printedPages == pageCount) {
                if (logerrors) cout << "All pages printed." << endl;
                if (jobInfo.jobType == "bw") {
                    if (logerrors) cout << "Printer " << selectedDeviceInfo.deviceName << " finished black-and-white job:" << endl;
                    if (logerrors) cout << "\t Job Number: " << jobInfo.jobNumber << endl;
                    if (logerrors) cout << "\t Submitted by: " << jobInfo.userName << endl;
                    if (logerrors) cout << "\t" << jobInfo.pageCount << " pages" << endl;
                    if (logerrors) cout << "Total cost of this job: " << jobInfo.totalCost << endl;
                    if (logerrors) cout << endl;
                }
                if (jobInfo.jobType == "color") {
                    if (logerrors) cout << "Printer " << selectedDeviceInfo.deviceName << " finished color-printing job:" << endl;
                    if (logerrors) cout << "\t Job Number: " << jobInfo.jobNumber << endl;
                    if (logerrors) cout << "\t Submitted by: " << jobInfo.userName << endl;
                    if (logerrors) cout << "\t" << jobInfo.pageCount << " pages" << endl;
                    if (logerrors) cout << "Total cost of this job: " << jobInfo.totalCost << endl;
                    if (logerrors) cout << endl;
                }
                break; // Exit the loop
            }
        }
        // Save the job information in processedJobs under the processed device
        bool foundDevice = false;
        // Iterate through processedJobs to find the device name
        for (auto &processedJob: processedJobs) {
            // If device name matches, push the job into the existing vector
            if (processedJob.first == selectedDeviceInfo.deviceName) {
                processedJob.second.push_back(job2);
                foundDevice = true;
                break;
            }
        }
        // If device name not found, create a new entry in processedJobs
        if (!foundDevice) {
            processedJobs.push_back({selectedDeviceInfo.deviceName, vector<Job>{job2}});
        }
    } else {
        int pageCount = jobInfo.pageCount; // Access pageCount directly from jobInfo
        // Process the first job in the job list
        int scannedPages = 0;
        if (logerrors) cout << "Starting the scanning process..." << endl;
        while (scannedPages < pageCount) {
            ++scannedPages; // Increment printed pages
            if (logerrors) cout << "Scanned pages: " << scannedPages << endl;
            // Check if all pages have been printed
            if (scannedPages == pageCount) {
                if (logerrors) cout << "All pages scanned." << endl;
                if (jobInfo.jobType == "scan") {
                    if (logerrors) cout << "Printer " << selectedDeviceInfo.deviceName << " finished scanning job:" << endl;
                    if (logerrors) cout << "\t Job Number: " << jobInfo.jobNumber << endl;
                    if (logerrors) cout << "\t Submitted by: " << jobInfo.userName << endl;
                    if (logerrors) cout << "\t" << jobInfo.pageCount << " pages" << endl;
                    if (logerrors) cout << "Total cost of this job: " << jobInfo.totalCost << endl;
                    if (logerrors) cout << endl;
                }
            }
        }
        // Save the job information in processedJobs under the processed device
        bool foundDevice = false;
        // Iterate through processedJobs to find the device name
        for (auto &processedJob : processedJobs) {
            // If device name matches, push the job into the existing vector
            if (processedJob.first == selectedDeviceInfo.deviceName) {
                processedJob.second.push_back(job2);
                foundDevice = true;
                break;
            }
        }
        // If device name not found, create a new entry in processedJobs
        if (!foundDevice) {
            processedJobs.push_back({selectedDeviceInfo.deviceName, vector<Job>{job2}});
        }
    }
    processedJobsVector.clear();
    for (const auto &processedJob: processedJobs) {
        processedJobsVector.emplace_back(1, processedJob);
    }
    return true;
}
bool Device::printProcessedJobs(){
    // Print the contents of processedJobs vector
    cout << "Contents of processedJobs vector:" << endl;
    // Takes the pair in the vector of pairs
    for (const auto &processedJobs2: processedJobsVector) {
        // Take the device's name and processed jobs from the pairs
        for (const auto &processedJob2: processedJobs2) {
                // Take the name of the device
                if (logerrors) cout << "Device Name: " << processedJob2.first << endl;
                if (logerrors) cout << "Jobs:" << endl;
                // Take the job vector
                for (const auto &job9: processedJob2.second) {
                    JobInfo jobInfo = job9.giveJobInfo(); // Get job9 information from the vector
                    if (logerrors) cout << "Job Number: " << jobInfo.jobNumber << endl;
                    if (logerrors) cout << "Page Count: " << jobInfo.pageCount << endl;
                    if (logerrors) cout << "Job Type: " << jobInfo.jobType << endl;
                    if (logerrors) cout << "Username: " << jobInfo.userName << endl;
                    if (logerrors) cout << "Total cost of this job: " << jobInfo.totalCost << endl;
                    if (logerrors) cout << endl;
                }
        }
    }
    return true;
}