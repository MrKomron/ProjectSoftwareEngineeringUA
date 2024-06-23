// Created by admin on 4/30/2024.
//============================================================================
// Name        : loggerClass.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Description : Declaration of the Logger class in C++
//============================================================================

#ifndef PROJECTSOFTWAREENGINEERINGUA_LOGGERCLASS_H
#define PROJECTSOFTWAREENGINEERINGUA_LOGGERCLASS_H

#include <string>
#include <iostream>
#include "XMLREADER/XMLReader.h"
#include "Job.h"

using namespace std;

class loggerLines {
public:
    /**
     * Prints a line of equal signs.
     *
     * \n ENSURE(true, "A line of equal signs is printed.");
     */
    static void lines();

    /**
     * Prints the start system message.
     *
     * \n ENSURE(true, "Start system message is printed.");
     */
    static void startSystem();

    /**
     * Prints the start automated processing message.
     *
     * \n ENSURE(true, "Start automated processing message is printed.");
     */
    static void startAutomated();

    /**
     * Prints a line for the automated loop count.
     *
     * \n REQUIRE(loopCount >= 0, "Loop count must be non-negative.");
     * \n ENSURE(true, "Automated loop count message is printed.");
     */
    static void lineAutomatedLoop(int loopCount);

    /**
     * Prints the start processed job message.
     *
     * \n ENSURE(true, "Start processed job message is printed.");
     */
    static void startProcessedJob();

    /**
     * Prints a line with the device name for the automated process.
     *
     * \n REQUIRE(!deviceName.empty(), "Device name must not be empty.");
     * \n ENSURE(true, "Automated process device name line is printed.");
     */
    static void lineAutomatedName(string deviceName);
};

class outputPrinter {
public:

    // static void startingScan();

    /**
     * Prints the message indicating the start of the printing process.
     *
     * \n ENSURE(true, "Start printing process message is printed.");
     */
    static void startingPrint();

    /**
     * Prints the accumulated pages of the device using automated process.
     *
     * \n REQUIRE(!deviceName.empty(), "Device name must not be empty.");
     * \n REQUIRE(accumulatedPages >= 0, "Accumulated pages must be non-negative.");
     * \n ENSURE(true, "Accumulated pages of the device are printed.");
     */
    static void accumulatedPagesDeviceAutomated(string deviceName, int accumulatedPages);

    /**
     * Prints the scanned pages count.
     *
     * \n REQUIRE(scannedPages >= 0, "Scanned pages must be non-negative.");
     * \n ENSURE(true, "Scanned pages count is printed.");
     */
    static void startingScan(int scannedPages);

    /**
     * Prints job details.
     *
     * \n REQUIRE(jobNumber >= 0, "Job number must be non-negative.");
     * \n REQUIRE(pageCount >= 0, "Page count must be non-negative.");
     * \n REQUIRE(!jobType.empty(), "Job type must not be empty.");
     * \n REQUIRE(!userName.empty(), "User name must not be empty.");
     * \n REQUIRE(totalCost >= 0, "Total cost must be non-negative.");
     * \n ENSURE(true, "Job details are printed.");
     */
    static void neemJobvector(int jobNumber, int pageCount, string jobType,string userName,int totalCost, int totalEmmisions);

    /**
     * Prints the message indicating all pages are printed.
     *
     * \n ENSURE(true, "All pages printed message is printed.");
     */
    static void allPagesPrinted();

    /**
     * Prints the message indicating all pages are scanned.
     *
     * \n ENSURE(true, "All pages scanned message is printed.");
     */
    static void allPagesScanned();

    /**
     * Prints the processed jobs.
     *
     * \n ENSURE(true, "Processed jobs are printed.");
     */
    static void printProcessedJobs();

    /**
     * Prints the details of a processed job for a device.
     *
     * \n REQUIRE(jobNumber >= 0, "Job number must be non-negative.");
     * \n REQUIRE(pageCount >= 0, "Page count must be non-negative.");
     * \n REQUIRE(!jobType.empty(), "Job type must not be empty.");
     * \n REQUIRE(!userName.empty(), "User name must not be empty.");
     * \n REQUIRE(totalCost >= 0, "Total cost must be non-negative.");
     * \n ENSURE(true, "Processed job details for a device are printed.");
     */
    static void printProcessedJobsDevice(int jobNumber, int pageCount, string jobType, string userName, int totalCost);

    /**
     * Prints the message indicating the completion of a black-and-white printing job.
     *
     * \n REQUIRE(!deviceName.empty(), "Device name must not be empty.");
     * \n REQUIRE(jobNumber >= 0, "Job number must be non-negative.");
     * \n REQUIRE(!jobUser.empty(), "Job user must not be empty.");
     * \n REQUIRE(pageCount >= 0, "Page count must be non-negative.");
     * \n REQUIRE(totalCost >= 0, "Total cost must be non-negative.");
     * \n ENSURE(true, "Black-and-white printing job completion message is printed.");
     */
    static void printerBWFinished(string deviceName, int jobNumber, string jobUser, int pageCount, int totalCost);

    /**
     * Prints the message indicating the completion of a color printing job.
     *
     * \n REQUIRE(!deviceName.empty(), "Device name must not be empty.");
     * \n REQUIRE(jobNumber >= 0, "Job number must be non-negative.");
     * \n REQUIRE(!jobUser.empty(), "Job user must not be empty.");
     * \n REQUIRE(pageCount >= 0, "Page count must be non-negative.");
     * \n REQUIRE(totalCost >= 0, "Total cost must be non-negative.");
     * \n ENSURE(true, "Color printing job completion message is printed.");
     */
    static void printerCOLFinished(string deviceName, int jobNumber, string jobUser, int pageCount, int totalCost);


    /**
     * Prints the message indicating the completion of a scanning job.
     *
     * \n REQUIRE(!deviceName.empty(), "Device name must not be empty.");
     * \n REQUIRE(jobNumber >= 0, "Job number must be non-negative.");
     * \n REQUIRE(!jobUser.empty(), "Job user must not be empty.");
     * \n REQUIRE(pageCount >= 0, "Page count must be non-negative.");
     * \n REQUIRE(totalCost >= 0, "Total cost must be non-negative.");
     * \n ENSURE(true, "Scanning job completion message is printed.");
     */
    static void scannerFinished(string deviceName, int jobNumber, string jobUser, int pageCount, int totalCost);

    /**
     * Prints the information of a device.
     *
     * \n REQUIRE(!deviceName.empty(), "Device name must not be empty.");
     * \n REQUIRE(emissions >= 0, "Emissions must be non-negative.");
     * \n REQUIRE(!deviceType.empty(), "Device type must not be empty.");
     * \n REQUIRE(speed >= 0, "Speed must be non-negative.");
     * \n REQUIRE(cost_per_page >= 0, "Cost per page must be non-negative.");
     * \n REQUIRE(accumulatedPages >= 0, "Accumulated pages must be non-negative.");
     * \n REQUIRE(totalEmissions >= 0, "Total emissions must be non-negative.");
     * \n REQUIRE(totalEarnings >= 0, "Total earnings must be non-negative.");
     * \n ENSURE(true, "Device information is printed.");
     */
    static void printerInfoDevice(string deviceName, int emissions, string deviceType, int speed, int cost_per_page, int accumulatedPages, int totalEmissions, int totalEarnings);

    /**
     * Prints the information of a job.
     *
     * \n REQUIRE(jobNumber >= 0, "Job number must be non-negative.");
     * \n REQUIRE(pageCount >= 0, "Page count must be non-negative.");
     * \n REQUIRE(!jobType.empty(), "Job type must not be empty.");
     * \n REQUIRE(!userName.empty(), "User name must not be empty.");
     * \n REQUIRE(totalCost >= 0, "Total cost must be non-negative.");
     * \n REQUIRE(totalEmissions >= 0, "Total emissions must be non-negative.");
     * \n ENSURE(true, "Job information is printed.");
     */
    static void printerInfoJob(int jobNumber, int pageCount, string jobType, string userName, int totalCost, int totalEmissions);

    /**
     * Prints the number of device entries.
     *
     * \n REQUIRE(size >= 0, "Size must be non-negative.");
     * \n ENSURE(true, "Number of device entries is printed.");
     */
    static void numberEntriesDevice(int size);

    /**
     * Prints the number of job entries.
     *
     * \n REQUIRE(size >= 0, "Size must be non-negative.");
     * \n ENSURE(true, "Number of job entries is printed.");
     */
    static void numberEntriesJob(int size);

    static void processedJobsHeader(string deviceName, int totalEmissionsDevice);
    static void processedJobsTail(int jobNumber, int pageCount, string jobType, string userName, int totalCost);
    static void updatedAccumulatedPagesAutomated(string deviceName, int accumulatedPages);
    static void debuggerLine(string symbol);
    static void printSpecificDeviceInfo(DeviceInfo deviceInfo);
    static void printSpecificJobInfo(JobInfo jobNumber);
    static void remainingAvailableJobs(string deviceName);
    static void printRemainingJobs(int jobNumber, int pageCount, string jobType, string userName);
    static void printUnprocessedJobs(int jobNumber, int pageCount, string jobType, string userName, int totalCost);
    static void startUnprocessedJobs();
    static void emptyLine(){cout << endl;}
    static void neemDeviceNaam();
    static void neemJobvector();
    static void writeDeviceInfoOutputToFile();
};

class errorPrinter{
public:

    /**
     * Prints an error message indicating no device found in the system.
     *
     * \n ENSURE(true, "Error message for no device found is printed.");
     */
    static void noDeviceFoundName(string deviceName);

    static void noJobNumberFound(int jobNumber);
    static void jobTypeNotMatch(int jobNumber);
    static void noDeviceTypeExist(string jobType);
    static void noDeviceSystem();
    static void noJobSystem();
};

class StatusReportPrinter {
public:
    /**
     * Generates a status report and writes it to a file.
     *
     * \n REQUIRE(!jobs.empty(), "Jobs list must not be empty.");
     * \n ENSURE(result == true, "Status report is successfully generated.");
     */
    static bool generateStatusReport(vector<Job> jobs);
};

#endif //PROJECTSOFTWAREENGINEERINGUA_LOGGERCLASS_H
