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
    ENSURE(true, "A line of equal signs is printed.");
}

void loggerLines::startSystem() {
    cout << "===============================================     START     ===============================================" << endl;
    cout << endl;
    ENSURE(true, "Start system message is printed.");
}

void loggerLines::startAutomated() {
    cout << "============================================ Automated Processing Started ============================================" << endl;
    cout << endl;
    ENSURE(true, "Start automated processing message is printed.");
}

void loggerLines::lineAutomatedLoop(int loopCount) {
    REQUIRE(loopCount >= 0, "Loop count must be non-negative.");
    cout << "==================================     " << loopCount << "     ==================================" << endl;
    cout << endl;
    ENSURE(true, "Automated loop count message is printed.");
}

void loggerLines::startProcessedJob() {
    cout << "========================   Processed Jobs   ========================" << endl;
    cout << endl;
    ENSURE(true, "Start processed job message is printed.");
}

void loggerLines::lineAutomatedName(string deviceName) {
    REQUIRE(!deviceName.empty(), "Device name must not be empty.");
    cout << "==========  " << deviceName << "  ==========" << endl;
    ENSURE(true, "Automated process device name line is printed.");
}

void outputPrinter::accumulatedPagesDeviceAutomated(string deviceName, int accumulatedPages) {
    REQUIRE(!deviceName.empty(), "Device name must not be empty.");
    REQUIRE(accumulatedPages >= 0, "Accumulated pages must be non-negative.");
    cout << "Accumulated page of the device " << deviceName << " using automated process: " << accumulatedPages << endl;
    ENSURE(true, "Accumulated pages of the device are printed.");
}

void outputPrinter::startingPrint() {
    cout << "Starting the printing process..." << endl;
    ENSURE(true, "Start printing process message is printed.");
}


void outputPrinter::startingScan() {
     cout << "Starting the scanning process..." << endl;
 }
/*====
void outputPrinter::startingScan(int scannedPages) {
    REQUIRE(scannedPages >= 0, "Scanned pages must be non-negative.");
    cout << "Scanned pages: " << scannedPages << endl;
    ENSURE(true, "Scanned pages count is printed.");
}
*/
void outputPrinter::neemJobvector(int jobNumber, int pageCount, string jobType, string userName, int totalCost, int totalEmissions) {
    REQUIRE(jobNumber >= 0, "Job number must be non-negative.");
    REQUIRE(pageCount >= 0, "Page count must be non-negative.");
    REQUIRE(!jobType.empty(), "Job type must not be empty.");
    REQUIRE(!userName.empty(), "User name must not be empty.");
    REQUIRE(totalCost >= 0, "Total cost must be non-negative.");
    cout << "Job Number: " << jobNumber << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "Job Type: " << jobType << endl;
    cout << "User Name: " << userName << endl;
    cout << "Total Cost: " << totalCost << endl;
    ENSURE(true, "Job details are printed.");
}

void outputPrinter::allPagesPrinted() {
    cout << endl;
    cout << "All pages printed." << endl;
    ENSURE(true, "All pages printed message is printed.");
}

void outputPrinter::allPagesScanned() {
    cout << endl;
    cout << "All pages scanned." << endl;
    ENSURE(true, "All pages scanned message is printed.");
}

void outputPrinter::printerBWFinished(string deviceName, int jobNumber, string jobUser, int pageCount, int totalCost) {
    cout << "Printer " << deviceName << " finished black-and-white job:" << endl;
    cout << "\t Job Number: " << jobNumber << endl;
    cout << "\t Submitted by: " << jobUser << endl;
    cout << "\t " << pageCount << " pages" << endl;
    cout << "Total cost of this job: " << totalCost << endl;
    cout << endl;
    ENSURE(true, "Black-and-white job finished message is printed.");
}

void outputPrinter::printerCOLFinished(string deviceName, int jobNumber, string jobUser, int pageCount, int totalCost) {
    cout << "Printer " << deviceName << " finished color-printing job:" << endl;
    cout << "\t Job Number: " << jobNumber << endl;
    cout << "\t Submitted by: " << jobUser << endl;
    cout << "\t " << pageCount << " pages" << endl;
    cout << "Total cost of this job: " << totalCost << endl;
    cout << endl;
    ENSURE(true, "Color-printing job finished message is printed.");
}

void outputPrinter::scannerFinished(string deviceName, int jobNumber, string jobUser, int pageCount, int totalCost) {
    cout << "Printer " << deviceName << " finished scanning job:" << endl;
    cout << "\t Job Number: " << jobNumber << endl;
    cout << "\t Submitted by: " << jobUser << endl;
    cout << "\t " << pageCount << " pages" << endl;
    cout << "Total cost of this job: " << totalCost << endl;
    cout << endl;
    ENSURE(true, "Scanning job finished message is printed.");
}

void outputPrinter::printerInfoDevice(string deviceName, int emissions, string deviceType, int speed, int cost_per_page, int accumulatedPages, int totalEmissions, int totalEarnings) {
    cout << "Device Name: " << deviceName << endl;
    cout << "Emissions: " << emissions << endl;
    cout << "Type: " << deviceType << endl;
    cout << "Speed: " << speed << endl;
    cout << "Cost per page: " << cost_per_page << endl;
    cout << "Accumulated Pages: " << accumulatedPages << endl;
    cout << "Total Emissions: " << totalEmissions << endl;
    cout << "Total Earnings: " << totalEarnings << endl;
    cout << endl;
    ENSURE(true, "Device information is printed.");
}

void outputPrinter::printerInfoJob(int jobNumber, int pageCount, string jobType, string userName, int totalCost, int totalEmissions) {
    cout << "Job Number: " << jobNumber << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "Type: " << jobType << endl;
    cout << "User Name: " << userName << endl;
    cout << "Total Cost: " << totalCost << endl;
    cout << "Total Emissions: " << totalEmissions << endl;
    cout << endl;
    ENSURE(true, "Job information is printed.");
}

void outputPrinter::numberEntriesDevice(int size) {
    cout << "Number of Device entries: " << size << endl;
    ENSURE(true, "Number of device entries is printed.");
}

void outputPrinter::numberEntriesJob(int size) {
    cout << "Number of Job entries: " << size << endl;
    ENSURE(true, "Number of job entries is printed.");
}

void outputPrinter::processedJobsHeader(string deviceName, int totalEmissionsDevice) {
    cout << "Device Name: " << deviceName << endl;
    cout << "Total Emissions of this device: " << totalEmissionsDevice << endl;
    cout << "Jobs:" << endl;
    ENSURE(true, "Processed jobs header is printed.");
}

void outputPrinter::processedJobsTail(int jobNumber, int pageCount, string jobType, string userName, int totalCost) {
    cout << "Job Number: " << jobNumber << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "Job Type: " << jobType << endl;
    cout << "Username: " << userName << endl;
    cout << "Total cost of this job: " << totalCost << endl;
    cout << endl;
    ENSURE(true, "Processed job tail is printed.");
}

void outputPrinter::debuggerLine(string symbol) {
    string line;
    for (int i = 0; i < 20; ++i) {
        line += symbol;
    }
    cout << line << endl;
    ENSURE(true, "Debugger line is printed.");
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
    ENSURE(true, "Specific device information is printed.");
}

void outputPrinter::printUnprocessedJobs(int jobNumber, int pageCount, string jobType, string userName, int totalCost) {
    cout << "Job Number: " << jobNumber << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "Job Type: " << jobType << endl;
    cout << "Username: " << userName << endl;
    cout << "Total cost of this job: " << totalCost << endl;
    cout << endl;
    ENSURE(true, "Unprocessed job information is printed.");
}

void outputPrinter::startUnprocessedJobs() {
    cout << "========================   Unprocessed Jobs   ========================" << endl;
    cout << endl;
    ENSURE(true, "Start unprocessed jobs message is printed.");
}

void outputPrinter::updatedAccumulatedPagesAutomated(string deviceName, int accumulatedPages) {
    REQUIRE(!deviceName.empty(), "Device name must not be empty.");
    REQUIRE(accumulatedPages >= 0, "Accumulated pages must be non-negative.");
    cout << "Updated accumulated page of the device " << deviceName << " using automated process: " << accumulatedPages << endl;
    ENSURE(true, "Updated accumulated pages of the device are printed.");
}

void outputPrinter::printRemainingJobs(int jobNumber, int pageCount, string jobType, string userName) {
    cout << "Job Number: " << jobNumber << ", Page Count: " << pageCount << ", Job Type: " << jobType << ", Username: " << userName << endl;
    ENSURE(true, "Remaining jobs information is printed.");
}

void outputPrinter::remainingAvailableJobs(string deviceName) {
    REQUIRE(!deviceName.empty(), "Device name must not be empty.");
    cout << "Available unassigned jobs for device " << deviceName << ":" << endl;
    ENSURE(true, "Remaining available jobs information is printed.");
}

void outputPrinter::printProcessedJobs() {
    cout << "========================   Contents of processedJobs vector   ========================" << endl;
    cout << endl;
    ENSURE(true, "Contents of processed jobs vector are printed.");
}

void errorPrinter::noDeviceSystem() {
    cerr << "No Device in the system." << endl;
    ENSURE(true, "Error message for no device found is printed.");
}

void errorPrinter::noJobSystem() {
    cerr << "No Job in the system." << endl;
    ENSURE(true, "Error message for no job found is printed.");
}

void errorPrinter::noDeviceTypeExist(string jobType) {
    REQUIRE(!jobType.empty(), "Job type must not be empty.");
    cerr << "Error: No devices exist for the specified job type: " << jobType << endl;
    ENSURE(true, "Error message for no devices of the specified job type is printed.");
}

void errorPrinter::noJobNumberFound(int jobNumber) {
    REQUIRE(jobNumber >= 0, "Job number must be non-negative.");
    cerr << "Job \"" << jobNumber << "\" not found." << endl;
    ENSURE(true, "Error message for no job number found is printed.");
}

void errorPrinter::jobTypeNotMatch(int jobNumber) {
    REQUIRE(jobNumber >= 0, "Job number must be non-negative.");
    cerr << "Job " << jobNumber << " type does not match the type of the Device." << endl;
    ENSURE(true, "Error message for job type mismatch is printed.");
}

void errorPrinter::noDeviceFoundName(string deviceName) {
    REQUIRE(!deviceName.empty(), "Device name must not be empty.");
    cerr << "No device found with the name " << deviceName << " in the list of devices" << endl;
    ENSURE(true, "Error message for no device found by name is printed.");
}

void outputPrinter::writeDeviceInfoOutputToFile()
{
    // outFile << "Device Name: " << device.getDeviceName() << "\n";
    // outFile << "Emissions: " << device.getEmissions() << "\n";
    // outFile << "Type: " << device.getDeviceType() << "\n";
    // outFile << "Speed: " << device.getSpeed() << "\n";
    // outFile << "Cost per page: " << device.getCostPerPage() << "\n";
    // outFile << "Accumulated Pages: " << device.getAccumulatedPages() << "\n";
}

void outputPrinter::printProcessedJobsDevice(int jobNumber, int pageCount, string jobType, string userName, int totalCost){
    REQUIRE(jobNumber >= 0, "Job number must be non-negative.");
    REQUIRE(pageCount >= 0, "Page count must be non-negative.");
    REQUIRE(!jobType.empty(), "Job type must not be empty.");
    REQUIRE(!userName.empty(), "User name must not be empty.");
    REQUIRE(totalCost >= 0, "Total cost must be non-negative.");

    cout << "Job Number: " << jobNumber << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "Job Type: " << jobType << endl;
    cout << "Username: " << userName << endl;
    cout << "Total cost of this job: " << totalCost << endl;

    ENSURE(true, "Processed job details for a device are printed.");
}





bool StatusReportPrinter::generateStatusReport(vector<Job> jobs) {
    //-REQUIRE(!jobs.empty(), "Jobs list must not be empty.");
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
    vector<pair<string, vector<Job>>> tempVector = device.processedJobsVector;
    for ( auto& firstVector : tempVector) {
        for (auto &processedJob: firstVector.second) {
            outputFile << "[Job #" << processedJob.giveJobInfo().jobNumber << "]" << endl;
            outputFile << "  * Owner: " << processedJob.giveJobInfo().userName << endl;
            outputFile << "  * Device: " << firstVector.first << endl;
            //outputFile << "  * Status: " << job.giveJobInfo().status << endl;
            outputFile << "  * Total pages: " << processedJob.giveJobInfo().pageCount << " pages" << endl;
            //outputFile << "  * Total CO2: " << job.giveJobInfo().totalCO2 << "g CO2" << endl;
            outputFile << "  * Total cost: " << processedJob.giveJobInfo().totalCost << " cents" << endl;
            outputFile << endl;
        }
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
    ENSURE(true, "Status report is successfully generated.");
    return true;
}
bool SimpleComputationPrinter::generateSimpleComputation() {
    // Create a text file and open it in write mode.
    ofstream outputFile("simple_computation.txt");

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return false; // Return non-zero to indicate failure
    } else {
        cout << "Successfully opened output file." << endl;
    }

    outputFile << "# === [System Computational Report] === #" << endl;
    outputFile << endl;

    vector<Device> devices = Device::devices;

    long totalCO2Emissions = 0;
    long totalEarnings = 0;
    long totalJobsDone = 0;

    vector<Device> tempBW;
    vector<Device> tempCOLOR;
    vector<Device> tempSCAN;
    for (auto &device : devices) {
        string type;
        if (device.getDeviceType() == "bw") {
            type = "Black and White";
        } else if (device.getDeviceType() == "color") {
            type = "Colored";
        } else if (device.getDeviceType() == "scan") {
            type = "Scan";
        } else {
            continue; // Skip devices that are not of the specified types
        }
        long deviceTotalCO2 = device.getTotalEmissions();
        long deviceTotalEarnings = device.getTotalEarnings();
        long deviceJobsDone = 0;
        // Save the job information in processedJobs under the processed device
        // Iterate through processedJobs to find the device name
        for (auto &processedJob : Device::processedJobsVector) {
            // If device name matches, push the job into the existing vector
            if (processedJob.first == device.getDeviceName()) {
                deviceJobsDone = processedJob.second.size();
                break;
            }
        }

        totalCO2Emissions += deviceTotalCO2;
        totalEarnings += deviceTotalEarnings;
        totalJobsDone += deviceJobsDone;

        outputFile << "--== " << type << " ==--" << endl;
        outputFile << device.getDeviceName() << ":" << endl;
        outputFile << "\t* CO2: " << device.getEmissions() << "g/page" << endl;
        outputFile << "\t* " << device.getSpeed() << " pages / minute" << endl;
        outputFile << "\t* " << device.getDeviceType() << endl;
        outputFile << "\t* " << device.getCostPerPage() << " cents / page" << endl;
        outputFile << "\t* Total CO2: " << deviceTotalCO2 << "g" << endl;
        outputFile << "\t* Total Earnings: " << deviceTotalEarnings << " cents" << endl;
        outputFile << "\t* Total Jobs Done: " << deviceJobsDone << endl;
        outputFile << endl;
    }

    outputFile << "--== Total ==--" << endl;
    outputFile << "Total Jobs done by all devices in the system: " << totalJobsDone << endl;
    outputFile << "Total Emissions of all devices in the system: " << totalCO2Emissions << endl;
    outputFile << "Total Earnings of all devices in the system: " << totalEarnings << endl;
    outputFile << "# ======================= #" << endl;

    outputFile.close();
    ENSURE(true, "Simple computation is successfully generated.");
    return true;
}

void coutDevicePrinter::printProcessedJobsHeader(string name) {
    cout << "Device Name: " << name << endl;
    cout << "Jobs:" << endl;
}
