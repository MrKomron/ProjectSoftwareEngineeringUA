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
#include "PrinterSystem.h"


using namespace std;                // Using namespace std to have a much simpler code without redundant "std::".

void PrinterSystem::systemStart() {
    // Load and parse XML file
    XMLReader xmlReader;
    Device device;
    Job job;
    System system;
    StatusReport statusReport;
    bool enable = true;
    bool enableOutput = false;
    bool enableError = true;
    system.redirectIOToFiles(enable, enableOutput, enableError);
    // Initialized the first reading of the XML file. This function is located in XMLREADER/XMLReader.cpp.
    if (!xmlReader.readerXML("XMLDataVoorTests/dataTypesAutomated.XML")) {
        cerr << "Failed to load XML file." << endl;
    }
    // For better readability and separates every component.
    cout << "===================================================================================================================" << endl;
    vector<Device> devices = device.populateFromXMLReader(xmlReader);
    vector<Job> jobs = job.populateFromXMLReader(xmlReader);
    cout << "===================================================================================================================" << endl;
    const string examplePrinter1 = "Office_Printer5";
    const int exampleJob1 = 1;
    system.schedulerManual(examplePrinter1, exampleJob1);
    cout << "===================================================================================================================" << endl;
    const string examplePrinter2 = "Office_Printer6";
    const int exampleJob2 = 2;
    system.schedulerManual(examplePrinter2, exampleJob2);
    cout << "===================================================================================================================" << endl;
    const string examplePrinter3 = "ColorPrinter";
    const int exampleJob5 = 7;
    system.schedulerManual(examplePrinter3, exampleJob5);
    cout << "===================================================================================================================" << endl;
    const int exampleJob6 = 8;
    system.schedulerManual(examplePrinter3, exampleJob6);
    cout << "===================================================================================================================" << endl;
    const int exampleJob7 = 9;
    system.schedulerManual(examplePrinter3, exampleJob7);
    cout << "===================================================================================================================" << endl;
    statusReport.generateStatusReport();
    cout << "===================================================================================================================" << endl;
    system.schedulerAutomated(devices, jobs);
    cout << "===================================================================================================================" << endl;
    if (device.printProcessedJobs())
        cout << "====================================================================================================================" << endl;
    system.redirectIOToFiles(enable=(false), enableOutput, enableError);
}