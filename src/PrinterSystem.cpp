//============================================================================
// Name        : main.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Implementation of the PrinterSystem class in C++
//============================================================================

#include <iostream>
#include "XMLREADER/XMLReader.h"    ////////////////////////////
#include "Device.h"                 ///Including the headers////
#include "Job.h"                    ///that are going to be/////
#include "StatusReport.h"           /////////used here//////////
#include "SystemProcessing.h"       ////////////////////////////
#include "PrinterSystem.h"
#include "loggerClass.h"

#include "loggerClass.h"

using namespace std;

System system1;

void PrinterSystem::systemStart() {
    Device device;
    Job job;
    XMLReader xmlReader;
    Device device5;
    Job job5;
    System system;
    bool enable = true;
    bool enableOutput = false;
    bool enableError = true;

    // Redirect IO to files
    system.redirectIOToFiles(enable, enableOutput, enableError);

    // Initialized the first reading of the XML file. This function is located in XMLREADER/XMLReader.cpp.
    if (!xmlReader.readerXML("C:\\Users\\Boss\\Desktop\\A.J._23-24\\PSE\\ProjectSoftwareEngineeringUA\\XMLDataVoorTests\\ValidData.XML")) {
        cerr << "Failed to load XML file." << endl;
    }

    vector<Device> devices = device5.populateFromXMLReader(xmlReader);
    vector<Job> jobs = job5.populateFromXMLReader(xmlReader);
    loggerLines::lines();
    // Schedule an example job manually
    const string examplePrinter1 = "Office_Printer5";
    const int exampleJob1 = 1;
    system.schedulerManual(examplePrinter1, exampleJob1, jobs);
    loggerLines::lines();
    const string examplePrinter2 = "Office_Printer6";
    const int exampleJob2 = 2;
    system.schedulerManual(examplePrinter2, exampleJob2, jobs);
    loggerLines::lines();
    // Print the device and job lists
    device.printDeviceList();
    //job.printJobList(jobs);
    loggerLines::lines();
    // Generate the status report ????
    SimpleComputationPrinter::generateSimpleComputation();
    StatusReportPrinter::generateStatusReport(jobs);

    // Stop redirecting IO to files
    system.redirectIOToFiles(enable= false, enableOutput, enableError);

    ENSURE(true, "Printer system started and XML data processed.");
}
