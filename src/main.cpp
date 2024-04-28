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
#include <fstream> // Include fstream for file operations

using namespace std;                // Using namespace std to have a much simpler code without redundant "std::".

int main() {


    // Load and parse XML file
    XMLReader xmlReader;
    TiXmlDocument doc;
    // Initialized the first reading of the XML file. This function is located in XMLREADER/XMLReader.cpp.
    if (!xmlReader.readerXML("XMLDataVoorTests/dataTypesAutomated.XML")) {
        cerr << "Failed to load XML file." << endl;
        return 1;                   // Return a 1 to exit the program because it couldn't open the XML file.
    }                               // Without the parsing of the XML, the program wouldn't work.
    cout << "__________________________________________________________________" << endl; // For better readability and separates every component.
    // Process the parsed data after populating the vectors

    /*
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
    */
    /*
    if (report.generateStatusReport(devices, jobs)) {
        cout << "Status report generated successfully." << endl;
        cout << "__________________________________________________________________" << endl;
    } else {
        cerr << "Failed to generate status report." << endl;
        cout << "__________________________________________________________________" << endl;
    }
    */
    Device device;
    Job job;
    vector<Device> devices = device.populateFromXMLReader(xmlReader);
    vector<Job> jobs = job.populateFromXMLReader(xmlReader);
    cout << "===================================================================================================================" << endl;
    System system;
    const string examplePrinter1 = "Office_Printer5";
    const int exampleJob1 = 1;
    system.schedulerManual(examplePrinter1, exampleJob1, devices, jobs);
    cout << "===================================================================================================================" << endl;
    const string examplePrinter2 = "Office_Printer6";
    const int exampleJob2 = 2;
    system.schedulerManual(examplePrinter2, exampleJob2, devices, jobs);
    cout << "===================================================================================================================" << endl;
    const string examplePrinter3 = "ColorPrinter";
    const int exampleJob5 = 7;
    system.schedulerManual(examplePrinter3, exampleJob5, devices, jobs);
    cout << "===================================================================================================================" << endl;
    const int exampleJob6 = 8;
    system.schedulerManual(examplePrinter3, exampleJob6, devices, jobs);
    cout << "===================================================================================================================" << endl;
    const int exampleJob7 = 9;
    system.schedulerManual(examplePrinter3, exampleJob7, devices, jobs);
    cout << "===================================================================================================================" << endl;
    system.schedulerAutomated(devices, jobs);
    cout << "===================================================================================================================" << endl;
    if (device.printProcessedJobs())
        cout << "====================================================================================================================" << endl;
    return 0;
}