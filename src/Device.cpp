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
#include "loggerClass.h"

using namespace std;

Device::Device(const string &name, int emissions, const string &deviceType, int speed, int cost_per_page, int accumulatedPages)
        : deviceName(name), emissions(emissions), deviceType(deviceType), speed(speed), cost_per_page(cost_per_page), accumulatedPages(accumulatedPages){}

// Static member function to populate devices from XMLReader
vector<Device> Device::devices;
vector<Device> Device::populateFromXMLReader(const XMLReader& xmlReader) {
    // Access vectors from XMLReader
    const vector<DeviceInfo>& deviceInfoList = xmlReader.getDeviceInfoList();
    // Print the size of jobInfoList to verify if it's populated correctly
    cout << "Number of Device entries: " << deviceInfoList.size() << endl;
    // Clear any existing devices before populating new ones.
    devices.clear();
    // Populate Device objects using data from deviceInfoList vector
    for (auto& deviceInfo : deviceInfoList) {
        Device device(deviceInfo.deviceName, deviceInfo.emissions, deviceInfo.deviceType, deviceInfo.speed, deviceInfo.costpp, deviceInfo.accumulatedPages);
        devices.push_back(device);
    }
    return devices;
}
// This is a function use to print each one of the contents in the list of Devices.
void Device::printDeviceInfo() const {
    cout << "Device Name: " << deviceName << endl;
    cout << "Emissions: " << emissions << endl;
    cout << "Type: " << deviceType << endl;
    cout << "Speed: " << speed << endl;
    cout << "Cost per page: " << cost_per_page << endl;
    cout << "Accumulated Pages: " << accumulatedPages << endl;
}
DeviceInfo Device::giveDeviceInfo() const {
    DeviceInfo info;
    info.deviceName = deviceName;
    info.emissions = emissions;
    info.deviceType = deviceType;
    info.speed = speed;
    info.costpp = cost_per_page;
    info.accumulatedPages = accumulatedPages;
    info.totalEmissions = totalEmissions;
    info.totalEarnings = totalEarnings;
    return info;
}
vector<vector<pair<string, vector<Job>>>> Device::processedJobsVector;
bool Device::manualProcess(const DeviceInfo& selectedDevice, JobInfo& job){
    JobInfo jobInfo = job;
    DeviceInfo selectedDeviceInfo = selectedDevice;
    jobInfo.totalCost = jobInfo.pageCount * selectedDeviceInfo.costpp;
    Job job2(jobInfo.jobNumber, jobInfo.pageCount, jobInfo.jobType, jobInfo.userName, jobInfo.totalCost);
    job2.setNewTotalCost(jobInfo.totalCost);
    if (jobInfo.jobType == "bw" or jobInfo.jobType == "color") {
        int pageCount = jobInfo.pageCount; // Access pageCount directly from jobInfo
        // Process the first job in the job list
        int printedPages = 0;
        cout << "Starting the printing process..." << endl;
        while (printedPages < pageCount) {
            ++printedPages; // Increment printed pages
            // Check if all pages have been printed
            if (printedPages == pageCount) {
                cout << endl;
                cout << "All pages printed." << endl;
                if (jobInfo.jobType == "bw") {
                    cout << "Printer " << selectedDeviceInfo.deviceName << " finished black-and-white job:" << endl;
                    cout << "\t Job Number: " << jobInfo.jobNumber << endl;
                    cout << "\t Submitted by: " << jobInfo.userName << endl;
                    cout << "\t" << jobInfo.pageCount << " pages" << endl;
                    cout << "Total cost of this job: " << jobInfo.totalCost << endl;
                    cout << endl;
                }
                if (jobInfo.jobType == "color") {
                    cout << "Printer " << selectedDeviceInfo.deviceName << " finished color-printing job:" << endl;
                    cout << "\t Job Number: " << jobInfo.jobNumber << endl;
                    cout << "\t Submitted by: " << jobInfo.userName << endl;
                    cout << "\t" << jobInfo.pageCount << " pages" << endl;
                    cout << "Total cost of this job: " << jobInfo.totalCost << endl;
                    cout << endl;
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
        cout << "Starting the scanning process..." << endl;
        while (scannedPages < pageCount) {
            ++scannedPages; // Increment printed pages
            cout << "Scanned pages: " << scannedPages << endl;
            // Check if all pages have been printed
            if (scannedPages == pageCount) {
                cout << "All pages scanned." << endl;
                if (jobInfo.jobType == "scan") {
                    cout << "Printer " << selectedDeviceInfo.deviceName << " finished scanning job:" << endl;
                    cout << "\t Job Number: " << jobInfo.jobNumber << endl;
                    cout << "\t Submitted by: " << jobInfo.userName << endl;
                    cout << "\t" << jobInfo.pageCount << " pages" << endl;
                    cout << "Total cost of this job: " << jobInfo.totalCost << endl;
                    cout << endl;
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
    cout << "========================   Contents of processedJobs vector   ========================" << endl;
    cout << endl;
    // Takes the pair in the vector of pairs
    for (const auto &processedJobs2: processedJobsVector) {
        // Take the device's name and processed jobs from the pairs
        for (const auto &processedJob2: processedJobs2) {
                // Take the name of the device
                cout << "Device Name: " << processedJob2.first << endl;
                cout << "Jobs:" << endl;
                // Take the job vector
                for (const auto &job9: processedJob2.second) {
                    JobInfo jobInfo = job9.giveJobInfo(); // Get job9 information from the vector
                    cout << "Job Number: " << jobInfo.jobNumber << endl;
                    cout << "Page Count: " << jobInfo.pageCount << endl;
                    cout << "Job Type: " << jobInfo.jobType << endl;
                    cout << "Username: " << jobInfo.userName << endl;
                    cout << "Total cost of this job: " << jobInfo.totalCost << endl;
                    cout << endl;
                }
        }
    }
    return true;
}
void Device::printDeviceList(vector<Device> deviceList) {
    for (auto &device : deviceList){
        device.printDeviceInfo();
    }
}
DeviceInfo Device::getDeviceInfo(string deviceNameToFind) {
    for (auto &device: devices){
        if (device.deviceName == deviceNameToFind) {
            DeviceInfo deviceInfo = device.giveDeviceInfo();
            deviceInfo.deviceName = deviceName;
            deviceInfo.emissions = emissions;
            deviceInfo.deviceType = deviceType;
            deviceInfo.speed = speed;
            deviceInfo.costpp = cost_per_page;
            deviceInfo.accumulatedPages = accumulatedPages;
            return deviceInfo;
        }
    }
    cerr << "No device found with the name " <<deviceNameToFind<< " in the list of devices" << endl;
    // If no matching device is found, return a default DeviceInfo object
    return DeviceInfo();
}
void Device::writeDeviceInfoOutputToFile(vector<Device>& deviceList, string& fileName) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << "Number of Device entries: " << deviceList.size() << "\n";
        for (const auto& device : deviceList) {
            outFile << "Device Name: " << device.getDeviceName() << "\n";
            outFile << "Emissions: " << device.getEmissions() << "\n";
            outFile << "Type: " << device.getDeviceType() << "\n";
            outFile << "Speed: " << device.getSpeed() << "\n";
            outFile << "Cost per page: " << device.getCostPerPage() << "\n";
            outFile << "Accumulated Pages: " << device.getAccumulatedPages() << "\n";
        }
        outFile.close();
    }
}
//vector<Job> Device::getUnprocessedJobs() {
//    return unprocessedJobs;
//}
//void Device::resetAccumulatedPages() {
//    int accumulatedPages = 0;
//}
