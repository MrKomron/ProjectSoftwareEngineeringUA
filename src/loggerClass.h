//
// Created by admin on 4/30/2024.
//

#ifndef PROJECTSOFTWAREENGINEERINGUA_LOGGERCLASS_H
#define PROJECTSOFTWAREENGINEERINGUA_LOGGERCLASS_H
#include <string>
#include <iostream>
#include "XMLREADER/XMLReader.h"
#include "Job.h"
using namespace std;

class loggerLines {
public:
    static void lines();
    static void startSystem();
    static void startAutomated();
    static void lineAutomatedLoop(int loopCount);
    static void startProcessedJob();
    static void lineAutomatedName(string deviceName);
};
class outputPrinter{
public:
    static void startingPrint();
    static void startingScan();
    static void allPagesPrinted();
    static void allPagesScanned();
    static void printerBWFinished(string deviceName, int jobNumber, string jobUser, int pageCount, int totalCost);
    static void printerCOLFinished(string deviceName, int jobNumber, string jobUser, int pageCount, int totalCost);
    static void scannerFinished(string deviceName, int jobNumber, string jobUser, int pageCount, int totalCost);
    static void printerInfoDevice(string deviceName, int emissions, string deviceType, int speed, int cost_per_page, int accumulatedPages, int totalEmissions, int totalEarnings);
    static void printerInfoJob(int jobNumber, int pageCount, string jobType, string userName, int totalCost, int totalEmissions);
    static void numberEntriesDevice(int size);
    static void numberEntriesJob(int size);
    static void processedJobsHeader(string deviceName, int totalEmissionsDevice);
    static void processedJobsTail(int jobNumber, int pageCount, string jobType, string userName, int totalCost);
    static void accumulatedPagesDeviceAutomated(string deviceName, int accumulatedPages);
    static void updatedAccumulatedPagesAutomated(string deviceName, int accumulatedPages);
    static void debuggerLine(string symbol);
    static void printSpecificDeviceInfo(DeviceInfo deviceInfo);
    static void printSpecificJobInfo(JobInfo jobNumber);
    static void remainingAvailableJobs(string deviceName);
    static void printRemainingJobs(int jobNumber, int pageCount, string jobType, string userName);
    static void printUnprocessedJobs(int jobNumber, int pageCount, string jobType, string userName, int totalCost);
    static void startUnprocessedJobs();
    static void emptyLine(){cout << endl;}
};
class errorPrinter{
public:
    static void noDeviceFoundName(string deviceName);
    static void noJobNumberFound(int jobNumber);
    static void jobTypeNotMatch(int jobNumber);
    static void noDeviceTypeExist(string jobType);
    static void noDeviceSystem();
    static void noJobSystem();
};

class StatusReportPrinter
{
public:
    static bool generateStatusReport(vector<Job> jobs);

};

#endif //PROJECTSOFTWAREENGINEERINGUA_LOGGERCLASS_H
