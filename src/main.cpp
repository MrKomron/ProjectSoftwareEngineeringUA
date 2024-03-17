//============================================================================
// Name        : main.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================
#include <iostream>
#include "XMLREADER/XMLReader.h"    ////////////////////////////
#include "Device.h"                 ///Including the headers////
#include "Job.h"                    ///that are going to be/////
#include "StatusReport.h"           /////////used here//////////
#include "SystemProcessing.h"       ////////////////////////////

using namespace std;                // Using namespace std to have a much simpler code without redundant "std::".

int main() {
    // Load and parse XML file
    XMLReader xmlReader;
    // Initialized the first reading of the XML file. This function is located in XMLREADER/XMLReader.cpp.
    if (!xmlReader.readerXML("XMLDataVoorTests/NoDAta.xml")) {
        cerr << "Failed to load XML file." << endl;
        return 1;                   // Return a 1 to exit the program because it couldn't open the XML file.
    }                               // Without the parsing of the XML, the program wouldn't work.
    cout << "__________________________________________________________________" << endl; // For better readability and separates every component.
    // Process the parsed data after populating the vectors
    Device device;
    Job job;
    System system;
    StatusReport report;
    // Process the parsed data after populating the vectors.
    device.populateFromXMLReader(xmlReader);
    cout << "Device List:" << endl;
    bool foundDevice = false;
    // Populate devices from XMLReader.
    for (const auto& device : Device::devices) {
        // Call the print function.
        device.printDeviceInfo();
        // Add a newline for better readability
        cout << endl;
        foundDevice = true;
    }
    if (!foundDevice) {
        cerr << "No device found." << endl;
    }
    cout << "__________________________________________________________________" << endl;
    // Process the parsed data after populating the vectors
    job.populateFromXMLReader(xmlReader);
    cout << "Job List:"<< endl;
    // Populate jobs from XMLReader.
    for (const auto& job : Job::jobs) {
        // Call the print function.
        job.printJobInfo();
        // Add a newline for better readability.
        cout << endl;
    }
    cout << "__________________________________________________________________" << endl;
    if (system.manualProcess(Device::devices, Job::jobs) == 0){
        cout << "__________________________________________________________________" << endl;
    }

    else {
        cerr << "Failed to process the request." << endl;
    }
    if (report.generateStatusReport(Device::devices, Job::jobs) == 0) {
        cout << "Status report generated successfully." << endl;
        return 0;
    } else {
        cerr << "Failed to generate status report." << endl;
        return 1;
    }
}