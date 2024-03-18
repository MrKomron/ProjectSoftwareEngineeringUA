//============================================================================
// Name        : Device.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================
#include <fstream>
#include <iostream>
#include "Device.h"
#include "XMLREADER/XMLReader.h"

using namespace std;
vector<Device> Device::devices;
Device::Device(const string &name, int emissions, int speed)
        : deviceName(name), emissions(emissions), speed(speed) {}

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
        Device device(deviceInfo.deviceName, deviceInfo.emissions, deviceInfo.speed);
        devices.push_back(device);
    }
    return devices;
}
// This is a function use to print each one of the contents in the list of Devices.
void Device::printDeviceInfo() const {
    if (logerrors) cout << "Device Name: " << deviceName << endl;
    if (logerrors) cout << "Emissions: " << emissions << endl;
    if (logerrors) cout << "Speed: " << speed << endl;
}
// This function would be used to write the top part in the status report output.
void Device::getDeviceInfo(ofstream& outputFile) const {
    outputFile << deviceName <<"(C02: "<< emissions<< "g/page): "<< endl;
}
// Get the name of the device.
string Device::getDeviceName() const {
    return deviceName;
}