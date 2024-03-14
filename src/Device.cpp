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

// Static member function to populate jobs from XMLReader
void Device::populateFromXMLReader(const XMLReader& xmlReader) {
    // Access vectors from XMLReader
    const vector<DeviceInfo>& deviceInfoList = xmlReader.getDeviceInfoList();
    // Print the size of jobInfoList to verify if it's populated correctly
    cout << "Number of Device entries: " << deviceInfoList.size() << endl;
    // Clear any existing jobs before populating new ones
    // Assuming jobs is a static vector declared somewhere outside the class
    devices.clear();
    // Populate Device objects using data from deviceInfoList vector
    for (const auto& deviceInfo : deviceInfoList) {
        Device device(deviceInfo.deviceName, deviceInfo.emissions, deviceInfo.speed);
        devices.push_back(device);
    }
}
// This is a function use to print each one of the contents in the list of Devices.
void Device::printDeviceInfo() const {
    cout << "Device Name: " << deviceName << endl;
    cout << "Emissions: " << emissions << endl;
    cout << "Speed: " << speed << endl;
}
// This function would be used to write the top part in the status report output.
void Device::getDeviceInfo(ofstream& outputFile) const {
    outputFile << deviceName <<"(C02: "<< emissions<< "g/page): "<< endl;
}

string Device::getDeviceName() const {
    return deviceName;
}