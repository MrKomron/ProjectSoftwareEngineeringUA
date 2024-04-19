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

bool System::scheduler(const string& selectedDeviceName, int selectedJobNumber, const vector<Device>& devices, vector<Job>& jobs, const char logerror){
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
    // Call manualProcess on the device represented by deviceIter
    for (Device device : devices) {
        if (tempDeviceName == selectedDeviceName) {
            device.setlogerrors(logerror);
            // Call manualProcess on the device
            return device.manualProcess(selectedDeviceName, selectedJobNumber, jobs);
        }
    }

    // If device is not found
    if (logerrors) cerr << "Device \"" << selectedDeviceName << "\" not found." << endl;
    return false;
}