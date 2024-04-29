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
Job job1;
bool System::schedulerManual(const string& selectedDeviceName, int selectedJobNumber, vector<Job>& jobs){
    vector<Device> devices = device.devices;
    // Find the device with the specified deviceName
    auto deviceIter = find_if(devices.begin(), devices.end(), [&](const Device& dev) {
        DeviceInfo infoDev = dev.giveDeviceInfo();
        return infoDev.deviceName == selectedDeviceName;
    });
    // Check if the device was found
    if (deviceIter == devices.end()) {
        cerr << "Device \"" << selectedDeviceName << "\" not found." << endl;
        return false;
    }
    string tempDeviceName = deviceIter->giveDeviceInfo().deviceName;
    string tempDeviceType = deviceIter->giveDeviceInfo().deviceType;
    // Find the job with the specified jobNumber
    auto jobIter = find_if(jobs.begin(), jobs.end(), [&]( Job& job) {
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
            //job1.jobs.erase(jobIter);
            cout << "Remaining Jobs in the system: " <<  endl;
            //device.unprocessedJobs.clear();
            for (const auto& job : jobs) {
                JobInfo infoJob = job.giveJobInfo();
                //Job job2(infoJob.jobNumber, infoJob.pageCount, infoJob.jobType, infoJob.userName, infoJob.totalCost);
                cout << "Job Number: " << infoJob.jobNumber << ", Page Count: " << infoJob.pageCount << ", Job Type: "<< infoJob.jobType << ", Username: "<< infoJob.userName << endl;
                //device.unprocessedJobs.push_back(job2);
            }
            //device.unprocessedJobs= jobs;
        }
        return true;
    } else {
        cerr << "Job type does not match the type of the Device." << endl;
        return false;
    }
}
vector<Device> System::tempBW;
vector<Device> System::tempCOLOR;
vector<Device> System::tempSCAN;
bool System::schedulerAutomated(vector<Device>& devices1, vector<Job>& jobs) {
    cout << "===============================================     START     ===============================================" << endl;
    cout << "Starting Automated printing..." << endl << endl;
    for (auto &device1: devices1) {
        DeviceInfo deviceInfo = device1.giveDeviceInfo();
        Device device5(deviceInfo.deviceName, deviceInfo.emissions, deviceInfo.deviceType, deviceInfo.speed,
                       deviceInfo.costpp);
        if (deviceInfo.deviceType == "bw") {
            tempBW.push_back({device5});
        } else if (deviceInfo.deviceType == "color") {
            tempCOLOR.push_back({device5});
        } else if (deviceInfo.deviceType == "scan") {
            tempSCAN.push_back({device5});
        }
    }
    int counterLoop = 0;
    int firstNumber = 0;
    for (auto &job : jobs) {
        JobInfo jobInfo = job.giveJobInfo();
        vector<Device> *tempDevices = nullptr; // Initialize tempDevices to nullptr
        // Find the job with the specified jobNumber
        auto jobIter = find_if(jobs.begin(), jobs.end(), [&]( Job& job) {
            JobInfo infoJob = job.giveJobInfo(); // Get job information
            return infoJob.jobNumber == 0; // Check job number
        });
        if (jobInfo.jobType == "bw") {
            tempDevices = &tempBW;
        } else if (jobInfo.jobType == "color") {
            tempDevices = &tempCOLOR;
        } else if (jobInfo.jobType == "scan") {
            tempDevices = &tempSCAN;
        }
        //int minAccumulatedPages = INT_MAX;
        //Device* minAccumulatedDevice = nullptr;
        if (tempDevices->empty()) {
            cerr << "Error: No device exists for the specified job type.(" << jobInfo.jobType << ")" << endl;
            continue;
        }
        //cout << "Length of the tempDevices " << tempDevices->size() << endl;
        bool jobAssigned = false;
        if (tempDevices->size() > 1) {
            for (auto &deviceItem: *tempDevices) {
                DeviceInfo deviceInfo1 = deviceItem.giveDeviceInfo();
                string deviceName = deviceInfo1.deviceName;
                int current = deviceInfo1.accumulatedPages;
                if (current <= firstNumber && !jobAssigned) {
                    cout << "==========  " << deviceName << "  =========="<< endl;
                    cout << "Accumulated page of the first device using automated process: " << firstNumber << endl;
                    cout << "Accumulated page of the device " << deviceName << " using automated process: " << current << endl;
                    cout << endl;
                    if (device.manualProcess(deviceInfo1, jobInfo)){jobs.erase(jobIter);};
                    int newAccumulatedPages = deviceInfo1.accumulatedPages + jobInfo.pageCount;
                    deviceInfo1.accumulatedPages = newAccumulatedPages;
                    cout << "Updated accumulated page of the device "<< deviceName <<" using automated process: " << deviceInfo1.accumulatedPages << endl;
                    // Modify the accumulated pages of the specific device in the corresponding vector
                    if (jobInfo.jobType == "bw") {
                        // Update the vector tempBW
                        for (auto &bwDeviceItem : tempBW) {
                            DeviceInfo bwDeviceItemInfo = bwDeviceItem.giveDeviceInfo();
                            string bwDeviceItemName = bwDeviceItemInfo.deviceName;
                            if (bwDeviceItemName == deviceName) {
                                bwDeviceItem.setAccumulatedPages(newAccumulatedPages);
                                break; // Exit the loop once the specific device is found and updated
                            }
                        }
                    } else if (jobInfo.jobType == "color") {
                        // Update the vector tempCOLOR
                        for (auto &colorDeviceItem : tempCOLOR) {
                            DeviceInfo colorDeviceItemInfo = colorDeviceItem.giveDeviceInfo();
                            string colorDeviceItemName = colorDeviceItemInfo.deviceName;
                            if (colorDeviceItemName == deviceName) {
                                colorDeviceItem.setAccumulatedPages(newAccumulatedPages);
                                break; // Exit the loop once the specific device is found and updated
                            }
                        }
                    } else if (jobInfo.jobType == "scan") {
                        // Update the vector tempSCAN
                        for (auto &scanDeviceItem : tempSCAN) {
                            DeviceInfo scanDeviceItemInfo = scanDeviceItem.giveDeviceInfo();
                            string scanDeviceItemName = scanDeviceItemInfo.deviceName;
                            if (scanDeviceItemName == deviceName) {
                                scanDeviceItem.setAccumulatedPages(newAccumulatedPages);
                                break; // Exit the loop once the specific device is found and updated
                            }
                        }
                    }
                    jobAssigned = true;
                    ++counterLoop;
                    break;
                } else {
                    firstNumber = current;
                }
            }
        } else {
            for (auto &deviceItem: *tempDevices) {
                DeviceInfo deviceInfo1 = deviceItem.giveDeviceInfo();
                int current = deviceInfo1.accumulatedPages;
                string deviceName = deviceInfo1.deviceName;
                cout << "==========  " << deviceName << "  =========="<< endl;
                cout << "Accumulated page of the device " << deviceName << " using automated process: " << current << endl;
                cout << endl;
                if (device.manualProcess(deviceInfo1, jobInfo)){jobs.erase(jobIter);};
                int newAccumulatedPages = deviceInfo1.accumulatedPages + jobInfo.pageCount;
                deviceInfo1.accumulatedPages = newAccumulatedPages;
                cout << "Updated accumulated page of the device "<< deviceName<<" using automated process: " << deviceInfo1.accumulatedPages << endl;
                // Modify the accumulated pages of the specific device in the corresponding vector
                if (jobInfo.jobType == "bw") {
                    // Update the vector tempBW
                    for (auto &bwDeviceItem : tempBW) {
                        DeviceInfo bwDeviceItemInfo = bwDeviceItem.giveDeviceInfo();
                        string bwDeviceItemName = bwDeviceItemInfo.deviceName;
                        if (bwDeviceItemName == deviceName) {
                            bwDeviceItem.setAccumulatedPages(newAccumulatedPages);
                            break; // Exit the loop once the specific device is found and updated
                        }
                    }
                } else if (jobInfo.jobType == "color") {
                    // Update the vector tempCOLOR
                    for (auto &colorDeviceItem : tempCOLOR) {
                        DeviceInfo colorDeviceItemInfo = colorDeviceItem.giveDeviceInfo();
                        string colorDeviceItemName = colorDeviceItemInfo.deviceName;
                        if (colorDeviceItemName == deviceName) {
                            colorDeviceItem.setAccumulatedPages(newAccumulatedPages);
                            break; // Exit the loop once the specific device is found and updated
                        }
                    }
                } else if (jobInfo.jobType == "scan") {
                    // Update the vector tempSCAN
                    for (auto &scanDeviceItem : tempSCAN) {
                        DeviceInfo scanDeviceItemInfo = scanDeviceItem.giveDeviceInfo();
                        string scanDeviceItemName = scanDeviceItemInfo.deviceName;
                        if (scanDeviceItemName == deviceName) {
                            scanDeviceItem.setAccumulatedPages(newAccumulatedPages);
                            break; // Exit the loop once the specific device is found and updated
                        }
                    }
                }
                ++counterLoop;
            }
        }
        cout << "============================     " << counterLoop
             << "     ============================" << endl;
    }
    //device.resetAccumulatedPages();
    return true;
}
void System::redirectIOToFiles(bool enable, bool enableOutput, bool enableError) {
    if (enable) {
        if (enableOutput){redirectIOToFilesOutput();}
        if (enableError){redirectIOToFilesError();}
    } else {
        restoreIOFromFiles();
    }
}
void System::restoreIOFromFiles() {
    // Restore the original buffers so that outputs can be shown on terminal again if needed
    cout.rdbuf(coutBuf); // Reset to standard output before program exit
    cerr.rdbuf(cerrBuf); // Reset cerr to standard error
    outFile.close(); // Close the output file stream
    errFile.close(); // Close the error file stream
}
void System::redirectIOToFilesOutput() {
    outFile.open("output.txt");

    coutBuf = cout.rdbuf(); // Save old buffer for cout

    cout.rdbuf(outFile.rdbuf());
}
void System::redirectIOToFilesError() {

    errFile.open("errors.txt");

    cerrBuf = cerr.rdbuf(); // Save old buffer for cerr

    cerr.rdbuf(errFile.rdbuf());

}