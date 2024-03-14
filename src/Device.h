//============================================================================
// Name        : Device.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================
#ifndef TESTFOLDER_DEVICE_H
#define TESTFOLDER_DEVICE_H
#include <fstream>
#include <iostream>
#include "XMLREADER/XMLReader.h"
#include <string>
#include <vector>

class Device {
private:
    std::string deviceName;
    int emissions;
    int speed;

public:
    // Constructor
    Device(const std::string& name = "", int emissions = 0, int speed = 0);
    // Function to populate jobs from XMLReader
    static void populateFromXMLReader(const XMLReader& xmlReader);
    void printDeviceInfo() const;
    void getDeviceInfo(std::ofstream& outputFile) const;
    std::string getDeviceName() const;
    static std::vector<Device> devices;
};

#endif //TESTFOLDER_DEVICE_H