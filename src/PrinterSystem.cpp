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
#include "loggerClass.h"

#include "loggerClass.h"


using namespace std;                // Using namespace std to have a much simpler code without redundant "std::".
System system1;

void PrinterSystem::systemStart() {
    Device device;
    Job job;
    XMLReader xmlReader;
    Device device5;
    Job job5;
    System system;
    bool enable = true;
    bool enableOutput = true;
    bool enableError = true;
    system.redirectIOToFiles(enable, enableOutput, enableError);
    // Initialized the first reading of the XML file. This function is located in XMLREADER/XMLReader.cpp.
    if (!xmlReader.readerXML("XMLDataVoorTests/ValidData.XML")) {
        cerr << "Failed to load XML file." << endl;
    }
    vector<Device> devices = device5.populateFromXMLReader(xmlReader);
    vector<Job> jobs = job5.populateFromXMLReader(xmlReader);
    device.printDeviceList(devices);
    job.printJobList(jobs);

    const string examplePrinter1 = "Office_Printer5";
    const int exampleJob1 = 1;
    system.schedulerManual(examplePrinter1, exampleJob1, jobs);
    cout << "===================================================================================================================" << endl;
    StatusReportPrinter::generateStatusReport(jobs);
    system.redirectIOToFiles(enable= false, enableOutput, enableError);
}
