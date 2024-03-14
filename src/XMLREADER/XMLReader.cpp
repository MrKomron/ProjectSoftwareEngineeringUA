//============================================================================
// Name        : XMLReader.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================

#include "XMLReader.h"
#include "tinyxml.h"
#include <iostream>

using namespace std;

XMLReader::XMLReader() {
// Empty Constructor used in main.cpp to initialize the first reading/parsing of the XML file.

}
// A Boolean type function to return whether the parsing or reading of the file is successful or not.
bool XMLReader::readerXML(string filename) {
    // Creates an instance of TiXmlDocument class named "doc"


    //TiXmlDocument doc1;
    // Loads the file to start the parsing.
    if (!doc.LoadFile(filename.c_str())) {
        if (logerrors)
      if (logerrors) cerr << "Failed to load file: " << doc.ErrorDesc() << endl;
        // Returns a false if unable to open the file. (This then would be used to exit the program in main.cpp)
        return false;
    }
    // Checks the root of the XML file if it is "SYSTEM"
    TiXmlElement* root = doc.FirstChildElement("SYSTEM");
    if (!root) {
        if (logerrors)
      if (logerrors) cerr << "Failed to find root element SYSTEM." << endl;
        // Returns a false if root is not SYSTEM. (Without the system, the program is pretty much useless)
        return false;
    }
    // Sets a variable to be used later for the checking of the availability of any printing device in the system.
    bool foundDevice = false;
    // Loop through DEVICE elements
    for (TiXmlElement* deviceElement = root->FirstChildElement("DEVICE"); deviceElement; deviceElement = deviceElement->NextSiblingElement("DEVICE")) {
        // Create a new vector instance for every device found.
        DeviceInfo deviceInfo;
        // Get name element from DEVICE.
        TiXmlElement* nameElement = deviceElement->FirstChildElement("name");
        if (!nameElement) {
            if (logerrors)
          if (logerrors) cerr << "Failed to find NAME element for the device. Continuing onto the next attribute." << endl;
            continue;
        }
        // Get emissions element from DEVICE.
        TiXmlElement* emissionsElement = deviceElement->FirstChildElement("emissions");
        if (!emissionsElement) {
        if (logerrors) cerr << "Failed to find EMISSIONS element for the device. Continuing onto the next attribute." << endl;
            continue;
        }
        // Get speed element from DEVICE.
        TiXmlElement* speedElement = deviceElement->FirstChildElement("speed");
        if (!speedElement) {
        if (logerrors) cerr << "Failed to find SPEED element for the device. Continuing onto the next attribute." << endl;
            continue;
        }
        // Extract and convert values to integers if needed.
        const char* deviceNameText = nameElement->GetText();
        if (!deviceNameText) {
        if (logerrors) cerr << "Device name is empty for the device. Continuing onto the next attribute." << endl;
            continue;
        }
        deviceInfo.deviceName = deviceNameText;

        const char* emissionsText = emissionsElement->GetText();
        if (!emissionsText) {
        if (logerrors) cerr << "Emissions value is missing or empty for the device. Continuing onto the next attribute." << endl;
            continue;
        }
        deviceInfo.emissions = atoi(emissionsText);

        const char* speedText = speedElement->GetText();
        if (!speedText) {
        if (logerrors) cerr << "Speed value is missing or empty for the device. Continuing onto the next attribute." << endl;
            continue;
        }
        deviceInfo.speed = atoi(speedText);

        // Error handling and validation.
        if (deviceInfo.deviceName.empty()) {
        if (logerrors) cerr << "Device name is empty for the device." << endl;
            continue;
        }
        if (deviceInfo.emissions <= 0) {
        if (logerrors) cerr << "Invalid emissions value for device: " << deviceInfo.emissions << endl;
            continue;
        }
        if (deviceInfo.speed <= 0) {
        if (logerrors) cerr << "Invalid speed value for device: " << deviceInfo.speed << endl;
            continue;
        }
        // Sets the data in the list of devices.
        deviceInfoList.push_back(deviceInfo);
        // Initialize the value to true.
        foundDevice = true;
    }
    // Checks the value of the foundDevice.
    if (!foundDevice) {
    if (logerrors) cerr << "There is no device in the system." << endl;
    }
    // Loop through JOB elements.
    for (TiXmlElement* jobElement = root->FirstChildElement("JOB"); jobElement; jobElement = jobElement->NextSiblingElement("JOB")) {
        // Create a new Job object for each JOB element.
        JobInfo jobInfo;
        // Get jobNumber element from JOB.
        TiXmlElement* jobNumberElement = jobElement->FirstChildElement("jobNumber");
        if (!jobNumberElement) {
        if (logerrors) cerr << "Failed to find jobNumber element for a job. Continuing onto the next attribute." << endl;
            continue;
        }
        // Get pageCount element from JOB.
        TiXmlElement* pageCountElement = jobElement->FirstChildElement("pageCount");
        if (!pageCountElement) {
        if (logerrors) cerr << "Failed to find pageCount element for a job. Continuing onto the next attribute." << endl;
            continue;
        }
        // Get userName element from JOB.
        TiXmlElement* userNameElement = jobElement->FirstChildElement("userName");
        if (!userNameElement) {
        if (logerrors) cerr << "Failed to find userName element for a job. Continuing onto the next attribute." << endl;
            continue;
        }
        // Extract and convert values to integers if needed.
        const char* jobNumberText = jobNumberElement->GetText();
        if (!jobNumberText) {
        if (logerrors) cerr << "Job number is empty for the device. Continuing onto the next attribute." << endl;
            continue;
        }
        jobInfo.jobNumber = atoi(jobNumberElement->GetText());
        const char* pageCountText = pageCountElement->GetText();
        if (!pageCountText) {
        if (logerrors) cerr << "Page count is missing or empty for the device. Continuing onto the next attribute." << endl;
            continue;
        }
        jobInfo.pageCount = atoi(pageCountElement->GetText());
        const char* userNameText = userNameElement->GetText();
        if (!userNameText) {
        if (logerrors) cerr << "User name is missing or empty for the device. Continuing onto the next attribute." << endl;
            continue;
        }
        jobInfo.userName = userNameElement->GetText();
        // Sets the data in the list of devices.
        jobInfoList.push_back(jobInfo);
    }
    doc.Clear();
    return true; // Return true indicating successful XML reading
}