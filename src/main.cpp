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
    TiXmlDocument doc;
    // Initialized the first reading of the XML file. This function is located in XMLREADER/XMLReader.cpp.
    xmlReader.setlogerrors(true);
    if (!xmlReader.readerXML("XMLDataVoorTests/data.xml")) {
        cerr << "Failed to load XML file." << endl;
        return 1;                   // Return a 1 to exit the program because it couldn't open the XML file.
    }                               // Without the parsing of the XML, the program wouldn't work.
    xmlReader.setlogerrors(false);
    cout << "__________________________________________________________________" << endl; // For better readability and separates every component.
    // Process the parsed data after populating the vectors
    Device device;
    Job job;
    System system;
    StatusReport report;
    // Process the parsed data after populating the vectors.
    vector<Device> devices = device.populateFromXMLReader(xmlReader);
    cout << "Device List:" << endl;
    bool foundDevice = false;
    // Populate devices from XMLReader.
    for (auto& device1 : Device::devices) {
        device1.setlogerrors(true);
        // Call the print function.
        device1.printDeviceInfo();

        device1.setlogerrors(false);
        // Add a newline for better readability
        cout << endl;
        foundDevice = true;
    }
    if (!foundDevice) {
        cerr << "No device found." << endl;
    }
    cout << "__________________________________________________________________" << endl;
    // Process the parsed data after populating the vectors
    vector<Job> jobs = job.populateFromXMLReader(xmlReader);
    cout << "Job List:"<< endl;
    // Populate jobs from XMLReader.
    for (auto& job1 : Job::jobs) {
        job1.setlogerrors(true);
        // Call the print function.
        job1.printJobInfo();
        job1.setlogerrors(false);
        // Add a newline for better readability.
        cout << endl;
    }
    cout << "__________________________________________________________________" << endl;
    if (report.generateStatusReport(devices, jobs)) {
        cout << "Status report generated successfully." << endl;
        cout << "__________________________________________________________________" << endl;
    } else {
        cerr << "Failed to generate status report." << endl;
        cout << "__________________________________________________________________" << endl;
    }
    system.setlogerrors(true);
    if (system.manualProcess(devices, jobs)){
        cout << "__________________________________________________________________" << endl;
        system.setlogerrors(false);
    }
    else {
        cerr << "Failed to process the request." << endl;
    }
    system.setlogerrors(true);
    if (system.automatedProcess(devices, jobs)){
        cout << "__________________________________________________________________" << endl;
        system.setlogerrors(false);
    }
    return 0;
}