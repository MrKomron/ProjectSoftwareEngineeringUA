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
vector<Device> Device::devices;
Device::Device(const string &name, int emissions, const string &deviceType, int speed, int cost_per_page)
        : deviceName(name), emissions(emissions), deviceType(deviceType), speed(speed) {}

// Static member function to populate devices from XMLReader
vector<Device> Device::populateFromXMLReader(const XMLReader& xmlReader) {
    // Access vectors from XMLReader
    const vector<DeviceInfo>& deviceInfoList = xmlReader.getDeviceInfoList();
    // Print the size of deviceInfoList to verify if it's populated correctly
    if (logerrors) cout << "Number of Device entries: " << deviceInfoList.size() << endl;
    // Clear any existing devices before populating new ones.
    devices.clear();
    // Populate Device objects using data from deviceInfoList vector
    for (const auto& deviceInfo : deviceInfoList) {
        Device device(deviceInfo.deviceName, deviceInfo.emissions, deviceInfo.deviceType, deviceInfo.speed);
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
}
DeviceInfo Device::giveDeviceInfo() const {
    DeviceInfo info;
    info.deviceName = deviceName;
    info.emissions = emissions;
    info.deviceType = deviceType;
    info.speed = speed;
    info.costpp = cost_per_page;
    return info;
}

float Device::getCostPerPage() const {
    return cost_per_page;
}

bool Device::manualProcess(const string& selectedDeviceName, const int selectedJobNumber, vector<Job>& jobs){
    // Find the job with the specified jobNumber
    auto jobIter = find_if(jobs.begin(), jobs.end(), [&](const Job& job) {
        JobInfo infoJob = job.giveJobInfo(); // Get job information
        return infoJob.jobNumber == selectedJobNumber; // Check job number
    });
    // Get job information
    JobInfo jobInfo = jobIter->giveJobInfo();
    if (jobInfo.jobType == "bw" or jobInfo.jobType == "color") {
        int pageCount = jobInfo.pageCount; // Access pageCount directly from jobInfo
        // Process the first job in the job list
        int printedPages = 0;
        while (printedPages < pageCount) {
            ++printedPages; // Increment printed pages
            if (logerrors) cout << "Printed pages: " << printedPages << endl;
            // Check if all pages have been printed
            if (printedPages == pageCount) {
                if (logerrors) cout << "All pages printed." << endl;
                if (logerrors) cout << endl;
                break; // Exit the loop
            }
        }
        // Save the job information in processedJobs under the processed device
        bool foundDevice = false;
        // Iterate through processedJobs to find the device name
        for (auto &processedJob: processedJobs) {
            // If device name matches, push the job into the existing vector
            if (processedJob.first == selectedDeviceName) {
                processedJob.second.push_back(*jobIter);
                foundDevice = true;
                break;
            }
        }
        // If device name not found, create a new entry in processedJobs
        if (!foundDevice) {
            processedJobs.push_back({selectedDeviceName, vector<Job>{*jobIter}});
        }
        // Print the contents of processedJobs vector
        if (logerrors) cout << "Contents of processedJobs vector:" << endl;
        for (const auto &processedJob: processedJobs) {
            if (logerrors) cout << "Device Name: " << processedJob.first << endl;
            if (logerrors) cout << "Jobs:" << endl;
            for (const auto &job: processedJob.second) {
                JobInfo infoJob = job.giveJobInfo(); // Get job information
                if (logerrors) cout << "Job Number: " << infoJob.jobNumber << endl;
                if (logerrors) cout << "Page Count: " << infoJob.pageCount << endl;
                if (logerrors) cout << "Page Count: " << infoJob.jobType << endl;
                if (logerrors) cout << "Username: " << infoJob.userName << endl;
                if (logerrors) cout << endl;
                // Add more job information as needed
            }
        }
    } else {
        {
            int pageCount = jobInfo.pageCount; // Access pageCount directly from jobInfo
            // Process the first job in the job list
            int scannedPages = 0;
            while (scannedPages < pageCount) {
                ++scannedPages; // Increment printed pages
                if (logerrors) cout << "Scanned pages: " << scannedPages << endl;
                // Check if all pages have been printed
                if (scannedPages == pageCount) {
                    if (logerrors) cout << "All pages scanned." << endl;
                    if (logerrors) cout << endl;
                    break; // Exit the loop
                }
            }
            // Save the job information in processedJobs under the processed device
            bool foundDevice = false;
            // Iterate through processedJobs to find the device name
            for (auto &processedJob : processedJobs) {
                // If device name matches, push the job into the existing vector
                if (processedJob.first == selectedDeviceName) {
                    processedJob.second.push_back(*jobIter);
                    foundDevice = true;
                    break;
                }
            }
            // If device name not found, create a new entry in processedJobs
            if (!foundDevice) {
                processedJobs.push_back({selectedDeviceName, vector<Job>{*jobIter}});
            }
            // Print the contents of processedJobs vector
            if (logerrors) cout << "Contents of processedJobs vector:" << endl;
            for (const auto &processedJob: processedJobs) {
                if (logerrors) cout << "Device Name: " << processedJob.first << endl;
                if (logerrors) cout << "Jobs:" << endl;
                for (const auto &job: processedJob.second) {
                    JobInfo infoJob = job.giveJobInfo(); // Get job information
                    if (logerrors) cout << "Job Number: " << infoJob.jobNumber << endl;
                    if (logerrors) cout << "Page Count: " << infoJob.pageCount << endl;
                    if (logerrors) cout << "Page Count: " << infoJob.jobType << endl;
                    if (logerrors) cout << "Username: " << infoJob.userName << endl;
                    if (logerrors) cout << endl;
                    // Add more job information as needed
                }
            }
        }
    }
    // Erase the job
    jobs.erase(jobIter);
    for (const auto& job : jobs) {
        JobInfo infoJob = job.giveJobInfo();
        if (logerrors) cout << "Job Number: " << infoJob.jobNumber << ", Page Count: " << infoJob.pageCount << ", Job Type: "<< infoJob.jobType << ", Username: "<< infoJob.userName << endl;
        // Print other job information if needed
    }
    return true;
}

Device::Device(const std::string& name, double emissionsPerUnit)
        : deviceName(name), emissionsPerUnit(emissionsPerUnit) {}

double Device::getEmissionsPerUnit() const {
    return emissionsPerUnit;
}