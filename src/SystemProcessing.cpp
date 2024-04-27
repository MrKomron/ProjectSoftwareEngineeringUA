//============================================================================
// Name        : SystemProcessing.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include "Device.h"
#include "Job.h"
#include "SystemProcessing.h"

using namespace std;
Device device;

bool System::schedulerManual(const string& selectedDeviceName, int selectedJobNumber, const vector<Device>& devices, vector<Job>& jobs){
    // Find the device with the specified deviceName
    auto deviceIter = find_if(devices.begin(), devices.end(), [&](const Device& dev) {
        DeviceInfo infoDev = dev.giveDeviceInfo();
        return infoDev.deviceName == selectedDeviceName;
    });
    // Check if the device was found
    if (deviceIter == devices.end()) {
        if (logerrors) cerr << "Device \"" << selectedDeviceName << "\" not found." << endl;
        return false;
    }
    string tempDeviceName = deviceIter->giveDeviceInfo().deviceName;
    string tempDeviceType = deviceIter->giveDeviceInfo().deviceType;
    // Find the job with the specified jobNumber
    auto jobIter = find_if(jobs.begin(), jobs.end(), [&](const Job& job) {
        JobInfo infoJob = job.giveJobInfo(); // Get job information
        return infoJob.jobNumber == selectedJobNumber; // Check job number
    });
    // Get job information
    JobInfo jobInfo = jobIter->giveJobInfo();
    DeviceInfo deviceInfo = deviceIter->giveDeviceInfo();
    string selectedJobType = jobInfo.jobType;
    // Call manualProcess on the device represented by deviceIter
    if (tempDeviceName == selectedDeviceName && tempDeviceType == selectedJobType) {
        // Call manualProcess on the device
        if (device.manualProcess(deviceInfo, jobInfo)){
            // Erase the job
            jobs.erase(jobIter);
            if (logerrors) cout << "Remaining Jobs in the system: " <<  endl;
            for (const auto& job : jobs) {
                JobInfo infoJob = job.giveJobInfo();
                if (logerrors) cout << "Job Number: " << infoJob.jobNumber << ", Page Count: " << infoJob.pageCount << ", Job Type: "<< infoJob.jobType << ", Username: "<< infoJob.userName << endl;
            }
        }
        return true;
    } else {
        return false;
    }
}

bool System::schedulerAutomated(const vector<Device>& devices1, vector<Job>& jobs) {
    device.setlogerrors(true);
    if (logerrors) cout << "Starting Automated printing..." << endl << endl;
    vector<vector<Device>> tempBW;
    vector<vector<Device>> tempCOLOR;
    vector<vector<Device>> tempSCAN;
    for (const auto &device1 : devices1) {
        DeviceInfo deviceInfo = device1.giveDeviceInfo();
        Device device5(deviceInfo.deviceName, deviceInfo.emissions, deviceInfo.deviceType, deviceInfo.speed, deviceInfo.costpp);

        if (deviceInfo.deviceType == "bw") {
            tempBW.push_back({device5});
        } else if (deviceInfo.deviceType == "color") {
            tempCOLOR.push_back({device5});
        } else if (deviceInfo.deviceType == "scan") {
            tempSCAN.push_back({device5});
        }
    }

    for (const auto &job : jobs) {
        JobInfo jobInfo = job.giveJobInfo();

        vector<vector<Device>>* tempDevices = nullptr; // Initialize tempDevices to nullptr

        if (jobInfo.jobType == "bw") {
            tempDevices = &tempBW;
        } else if (jobInfo.jobType == "color") {
            tempDevices = &tempCOLOR;
        } else if (jobInfo.jobType == "scan") {
            tempDevices = &tempSCAN;
        }

        int minAccumulatedPages = INT_MAX;
        const Device* minAccumulatedDevice = nullptr;

        for (size_t i = 0; i < tempDevices->size(); ++i) {
            const vector<Device>& deviceGroup = (*tempDevices)[i];
            for (const Device& device1 : deviceGroup) {
                DeviceInfo deviceInfo =
                device1.accumulatedPages += jobInfo.pageCount;
                int accumulatedPages = device1.getAccumulatedPages();
                cout << "Device: " << device1.getDeviceName() << ", Accumulated Pages: " << accumulatedPages << endl;
                if (device1.getAccumulatedPages() <= minAccumulatedPages) {
                    minAccumulatedPages = device1.getAccumulatedPages();
                    minAccumulatedDevice = &device1;
                }
            }
        }

        if (minAccumulatedDevice != nullptr) {
            size_t index = -1;
            for (size_t i = 0; i < tempBW.size(); ++i) {
                if (tempBW[i][0].getDeviceName() == minAccumulatedDevice->getDeviceName()) {
                    index = i;
                    break;
                }
            }
            for (size_t i = 0; i < tempCOLOR.size(); ++i) {
                if (tempCOLOR[i][0].getDeviceName() == minAccumulatedDevice->getDeviceName()) {
                    index = i;
                    break;
                }
            }
            for (size_t i = 0; i < tempSCAN.size(); ++i) {
                if (tempSCAN[i][0].getDeviceName() == minAccumulatedDevice->getDeviceName()) {
                    index = i;
                    break;
                }
            }
            DeviceInfo minAccumulatedDeviceInfo = minAccumulatedDevice->giveDeviceInfo();
            System::schedulerManual(minAccumulatedDeviceInfo.deviceName, jobInfo.jobNumber, devices1, jobs);
            if (logerrors) cout << endl;
        } else {
            if (logerrors) cerr << "Error: No device exists for the specified job type.(" << jobInfo.jobType << ")" << endl;
        }

        // Reset minAccumulatedPages and minAccumulatedDevice for the next job
        minAccumulatedPages = INT_MAX;
        minAccumulatedDevice = nullptr;
    }
    return true;
}
    /*
    while (!jobs.empty()) {
        JobInfo jobInfo = jobs.begin()->giveJobInfo();
        auto jobInfoEnd = jobs.end();
        for (auto &device2 : devices1) {
            DeviceInfo deviceInfo = device2.giveDeviceInfo();
            if (deviceInfo.deviceType == jobInfo.jobType) {
                System::schedulerManual(deviceInfo.deviceName, jobInfo.jobNumber, devices1, jobs);
                if (logerrors) cout << endl;
                break; // Break the inner loop
            }
        }
        if (!jobs.empty() and jobInfoEnd == jobs.end()) {
            int remainingJobs = jobs.size();
            int counter = 0;
            while (counter != remainingJobs) {
                if (logerrors) cerr << "Error: No device exists for the specified job type." << endl;
                ++counter;
            }
            return true;
        }
    }
    return true;
}
             if (!jobs.empty() and jobInfoEnd == jobs.end()) {
            int remainingJobs = jobs.size();
            int counter = 0;
            while (counter != remainingJobs) {
                if (logerrors) cerr << "Error: No device exists for the specified job type." << endl;
                ++counter;
            }
            return true;
        }
JobInfo jobInfo1 = .giveJobInfo();
for (auto &device2: devices1) {
    DeviceInfo deviceInfo1 = device2.giveDeviceInfo();
    System::schedulerManual(deviceInfo1.deviceName, jobInfo1.jobNumber, devices1, jobs);
}*/