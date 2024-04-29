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
#include "PrinterSystem.h"
#include "testsMethods.h"

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
    string fileName1 = "MAIN";
    system.redirectIOToFiles(enable, enableOutput, enableError, fileName1);
    // Initialized the first reading of the XML file. This function is located in XMLREADER/XMLReader.cpp.
    if (!xmlReader.readerXML("XMLDataVoorTests/dataTypesAutomated.XML")) {
        cerr << "Failed to load XML file." << endl;
    }
    // For better readability and separates every component.
    cout << "===================================================================================================================" << endl;
    vector<Device> devices = device.populateFromXMLReader(xmlReader);
    device.printDeviceList(devices);
    vector<Job> jobs = job.populateFromXMLReader(xmlReader);
    job.printJobList(jobs);
    cout << "===================================================================================================================" << endl;
    const string examplePrinter1 = "Office_Printer5";
    const int exampleJob1 = 1;
    system.schedulerManual(examplePrinter1, exampleJob1, jobs);
    cout << "===================================================================================================================" << endl;
    const string examplePrinter2 = "Office_Printer6";
    const int exampleJob2 = 2;
    system.schedulerManual(examplePrinter2, exampleJob2, jobs);
    cout << "===================================================================================================================" << endl;
    const string examplePrinter3 = "ColorPrinter";
    const int exampleJob5 = 7;
    system.schedulerManual(examplePrinter3, exampleJob5, jobs);
    cout << "===================================================================================================================" << endl;
    const int exampleJob6 = 8;
    system.schedulerManual(examplePrinter3, exampleJob6, jobs);
    cout << "===================================================================================================================" << endl;
    const int exampleJob7 = 9;
    system.schedulerManual(examplePrinter3, exampleJob7, jobs);
    cout << "===================================================================================================================" << endl;
    statusReport.generateStatusReport(jobs);
    cout << "===================================================================================================================" << endl;
    system.schedulerAutomated(devices, jobs);
    cout << "===================================================================================================================" << endl;
    if (device.printProcessedJobs())
        cout << "====================================================================================================================" << endl;
    system.redirectIOToFiles(enable= false, enableOutput, enableError, fileName1);
}
void PrinterSystem::systemStartTests() {
    XMLReader xmlReader;
    Device device;
    Job job;
    System system;
    Tests test;
    bool enable = true;
    bool enableOutput = true;
    bool enableError = true;
    string fileName = "TESTS";
    system.redirectIOToFiles(enable, enableOutput, enableError, fileName);
    // Initialized the first reading of the XML file. This function is located in XMLREADER/XMLReader.cpp.
    if (!xmlReader.readerXML("XMLDataVoorTests/NoName.XML")) {
        cerr << "Failed to load XML file." << endl;
    }
    vector<Device> devices = device.populateFromXMLReader(xmlReader);
    vector<Job> jobs = job.populateFromXMLReader(xmlReader);
    test.testNoName();
    test.testNoEmmisions();
    test.testNoCost();
    test.testNoJobNumber();
    test.testNoPageCount();
    test.testNoSpeed();
    test.testNoType();
    test.testNoTypeJob();
    test.testNoUserName();

    system.redirectIOToFiles(enable= false, enableOutput, enableError, fileName);

}
