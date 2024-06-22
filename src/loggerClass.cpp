//
// Created by admin on 4/30/2024.
//

#include "loggerClass.h"
#include "XMLREADER/XMLReader.h"
#include <iostream>
#include <vector>

#include "Device.h"
#include "Job.h"

using namespace std;

void loggerLines::lines() {
    cout << "==============================================================================================" << endl;
    cout << endl;
}
void loggerLines::startSystem() {
    cout << "===============================================     START     ===============================================" << endl;
    cout << endl;
}
void loggerLines::startAutomated() {
    cout << "============================================ Automated Processing Started ============================================" << endl;
    cout << endl;
}
void loggerLines::lineAutomatedLoop(int loopCount) {
    cout << "==================================     "<<loopCount<<"     ==================================" << endl;
    cout << endl;
}
void loggerLines::startProcessedJob() {
    cout << "========================   Processed Jobs   ========================" << endl;
    cout << endl;
}
void loggerLines::lineAutomatedName(string deviceName) {
    cout << "==========  "<< deviceName <<"  =========="<< endl;
}
void outputPrinter::accumulatedPagesDeviceAutomated(std::string deviceName, int accumulatedPages) {
    cout << "Accumulated page of the device " << deviceName << " using automated process: " << accumulatedPages << endl;
}
void outputPrinter::startingPrint() {
    cout << "Starting the printing process..." << endl;
}
void outputPrinter::startingScan() {
    cout << "Starting the scanning process..." << endl;
}
void outputPrinter::allPagesPrinted() {
    cout << endl;
    cout << "All pages printed." << endl;
}
void outputPrinter::allPagesScanned() {
    cout << endl;
    cout << "All pages scanned." << endl;
}
void outputPrinter::printerBWFinished(string deviceName, int jobNumber,string jobUser, int pageCount, int totalCost){
    cout << "Printer " << deviceName << " finished black-and-white job:"
         << endl;
    cout << "\t Job Number: " << jobNumber << endl;
    cout << "\t Submitted by: " << jobUser << endl;
    cout << "\t " << pageCount << " pages" << endl;
    cout << "Total cost of this job: " << totalCost << endl;
    cout << endl;
}
void outputPrinter::printerCOLFinished(string deviceName, int jobNumber, string jobUser, int pageCount, int totalCost) {
    cout << "Printer " << deviceName << " finished color-printing job:"
         << endl;
    cout << "\t Job Number: " << jobNumber << endl;
    cout << "\t Submitted by: " << jobUser << endl;
    cout << "\t " << pageCount << " pages" << endl;
    cout << "Total cost of this job: " <<totalCost << endl;
    cout << endl;
}
void outputPrinter::scannerFinished(string deviceName, int jobNumber, string jobUser, int pageCount, int totalCost) {
    cout << "Printer " << deviceName << " finished scanning job:" << endl;
    cout << "\t Job Number: " << jobNumber << endl;
    cout << "\t Submitted by: " << jobUser << endl;
    cout << "\t " << pageCount << " pages" << endl;
    cout << "Total cost of this job: " << totalCost << endl;
    cout << endl;
}
void outputPrinter::printerInfoDevice(std::string deviceName, int emissions, std::string deviceType, int speed, int cost_per_page, int accumulatedPages, int totalEmissions, int totalEarnings) {
    cout << "Device Name: " << deviceName << endl;
    cout << "Emissions: " << emissions << endl;
    cout << "Type: " << deviceType << endl;
    cout << "Speed: " << speed << endl;
    cout << "Cost per page: " << cost_per_page << endl;
    cout << "Accumulated Pages: " << accumulatedPages << endl;
    cout << "Total Emissions: " << totalEmissions << endl;
    cout << "Total Earnings: " << totalEarnings << endl;
}
void outputPrinter::printerInfoJob(int jobNumber, int pageCount, string jobType, string userName, int totalCost, int totalEmissions) {
    cout << "Job Number: " << jobNumber << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "Type: " << jobType << endl;
    cout << "User Name: " << userName << endl;
    cout << "Total Cost: " << totalCost << endl;
    cout << "Total Emissions: " << totalEmissions << endl;
    cout << endl;
}
void outputPrinter::numberEntriesDevice(int size) {
    cout << "Number of Device entries: " << size << endl;
}
void outputPrinter::numberEntriesJob(int size) {
    cout << "Number of Job entries: " << size << endl;
}
void outputPrinter::processedJobsHeader(string deviceName, int totalEmissionsDevice) {
    cout << "Device Name: " << deviceName << endl;
    cout << "Total Emissions of this device: " << totalEmissionsDevice << endl;
    cout << "Jobs:" << endl;
}
void outputPrinter::processedJobsTail(int jobNumber, int pageCount, std::string jobType, std::string userName, int totalCost) {
    cout << "Job Number: " << jobNumber << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "Job Type: " << jobType << endl;
    cout << "Username: " << userName << endl;
    cout << "Total cost of this job: " << totalCost << endl;
    cout << endl;
}
void outputPrinter::debuggerLine(string symbol) {
    string line;
    for (int i = 0; i < 20; ++i) {
        line += symbol;
    }
    cout << line << endl;
}
void outputPrinter::printSpecificDeviceInfo(DeviceInfo deviceInfo) {
    cout << "Device Name: " << deviceInfo.deviceName << endl;
    cout << "Emissions: " << deviceInfo.emissions << endl;
    cout << "Type: " << deviceInfo.deviceType << endl;
    cout << "Speed: " << deviceInfo.speed << endl;
    cout << "Cost per page: " << deviceInfo.costpp << endl;
    cout << "Accumulated Pages: " << deviceInfo.accumulatedPages << endl;
    cout << "Total Emissions: " << deviceInfo.totalEmissions << endl;
    cout << "Total Earnings: " << deviceInfo.totalEarnings << endl;
    cout << endl;
}

void outputPrinter::printUnprocessedJobs(int jobNumber, int pageCount, string jobType, string userName, int totalCost) {
    cout << "Job Number: " << jobNumber << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "Job Type: " << jobType << endl;
    cout << "Username: " << userName << endl;
    cout << "Total cost of this job: " << totalCost << endl;
    cout << endl;
}

void outputPrinter::startUnprocessedJobs() {
    cout << "========================   Unprocessed Jobs   ========================" << endl;
    cout << endl;
}

void outputPrinter::updatedAccumulatedPagesAutomated(string deviceName, int accumulatedPages) {
    cout << "Updated accumulated page of the device "<< deviceName <<" using automated process: " << accumulatedPages << endl;
}

void outputPrinter::printRemainingJobs(int jobNumber, int pageCount, string jobType, string userName) {
    cout << "Job Number: " << jobNumber << ", Page Count: " << pageCount << ", Job Type: "<< jobType << ", Username: "<< userName << endl;
}

void outputPrinter::remainingAvailableJobs(string deviceName) {
    cout << "Available unassigned jobs for device " << deviceName << ":" << endl;
}

void errorPrinter::noDeviceSystem() {
    cerr << "No Device in the system." << endl;
}
void errorPrinter::noJobSystem() {
    cerr << "No Job in the system." << endl;
}
void errorPrinter::noDeviceTypeExist(string jobType) {
    cerr << "Error: No devices exist for the specified job type: " << jobType << endl;
}
void errorPrinter::noJobNumberFound(int jobNumber) {
    cerr << "Job \"" << jobNumber << "\" not found." << endl;
}
void errorPrinter::jobTypeNotMatch(int jobNumber) {
    cerr << "Job " << jobNumber << " type does not match the type of the Device." << endl;
}
void errorPrinter::noDeviceFoundName(string deviceName) {
    cerr << "No device found with the name " <<deviceName<< " in the list of devices" << endl;
}

bool StatusReportPrinter::generateStatusReport(vector<Job> jobs) {
    // Create a text file and open it in write mode.
    ofstream outputFile("status_report.txt");

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return false; // Return non-zero to indicate failure
    }

    else if (outputFile.is_open()) {
        cout << "Successfully opened output file." << endl;
    }

    //bool foundDevice = false;
    Device device;
    vector<Device> devices = device.devices;
    outputFile << "# === [System Status] === #" << endl;
    outputFile << endl;

    // Device information
    outputFile << "--== Devices ==--" << endl;
    outputFile << endl;

    for (auto& device1 : devices) {
        outputFile << "* " << device1.giveDeviceInfo().deviceName << ":" << endl;
        outputFile << "  * CO2: " << device1.giveDeviceInfo().emissions << "g/page" << endl;
        outputFile << "  * " << device1.giveDeviceInfo().speed << " pages / minute" << endl;
        outputFile << "  * " << device1.giveDeviceInfo().deviceType << endl;
        outputFile << "  * " << device1.giveDeviceInfo().costpp << " cents / page" << endl;
    }
    outputFile << endl;
    // Job information
    outputFile << "--== Processed Jobs ==--" << endl;
    outputFile << endl;
    vector<vector<pair<string, vector<Job>>>> tempVector = device.processedJobsVector;
    for ( auto& firstVector : tempVector) {
        for (auto &firstDevice : firstVector){
            for (auto &processedJob: firstDevice.second){
                outputFile << "[Job #" << processedJob.giveJobInfo().jobNumber << "]" << endl;
                outputFile << "  * Owner: " << processedJob.giveJobInfo().userName << endl;
                outputFile << "  * Device: " << firstDevice.first << endl;
                //outputFile << "  * Status: " << job.giveJobInfo().status << endl;
                outputFile << "  * Total pages: " << processedJob.giveJobInfo().pageCount << " pages" << endl;
                //outputFile << "  * Total CO2: " << job.giveJobInfo().totalCO2 << "g CO2" << endl;
                outputFile << "  * Total cost: " << processedJob.giveJobInfo().totalCost << " cents" << endl;
                outputFile << endl;
            }
        }
        /*
        outputFile << "[Job #" << job1.giveJobInfo().jobNumber << "]" << endl;
        outputFile << "  * Owner: " << job1.giveJobInfo().userName << endl;
        outputFile << "  * Device: " << device.giveDeviceInfo().deviceName << endl;
        //outputFile << "  * Status: " << job.giveJobInfo().status << endl;
        outputFile << "  * Total pages: " << job1.giveJobInfo().pageCount << " pages" << endl;
        //outputFile << "  * Total CO2: " << job.giveJobInfo().totalCO2 << "g CO2" << endl;
        outputFile << "  * Total cost: " << job1.giveJobInfo().totalCost << " cents" << endl;
        outputFile << endl;
         */
    }
    outputFile << "--== Waiting Jobs ==--" << endl;
    for (auto &job : jobs) {
        outputFile << "[Job #" << job.giveJobInfo().jobNumber << "]" << endl;
        outputFile << "  * Owner: " << job.giveJobInfo().userName << endl;
        outputFile << "  * Device: " << "**Unassigned**" << endl;
        outputFile << "  * Status: " << "**Unassigned**" << endl;
        outputFile << "  * Total pages: " << job.giveJobInfo().pageCount << " pages" << endl;
        //outputFile << "  * Total CO2: " << job.giveJobInfo().totalCO2 << "g CO2" << endl;
        outputFile << "  * Total cost: " << job.giveJobInfo().totalCost << " cents" << endl;
        outputFile << endl;
    }
    outputFile << "# ======================= #" << endl;

    outputFile.close();
    return true;
}