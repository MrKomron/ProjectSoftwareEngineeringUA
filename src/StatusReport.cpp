//============================================================================
// Name        : StatusReport.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================


/*
 OLD VERSION.

Goal: The system should print an easy-to-read status report.

Precondition: A valid printing system is loaded.

Postcondition: The system has created a text file (ASCII) that contains all the necessary information about the system.


Steps:
    1. Create output file.
    2. WHILE printers left
    2.1. Print information about the printer to the output file.
    3. WHILE jobs left
    3.1. Print information about the job to the output file.
    4. Close output file.


Example:
    NEW-Printer (CO2: 5g/page):
    * Current:
    [#789|KasperEngelen]
    * Queue:
    [#423|Peter Selie]
    [#98712|New-user]



 NEW VERSION.

 Goal: To gain better insight into the system, the University wants to have a more extensive output.
For example, the jobs should be printed in more detail, and there needs to be more detailed info about
the amount of pages.

Note: Depending on which other use cases have been implemented, this use case might display
different information!

Precondition: Same as old version.

Postcondition: The system has created a text file (ASCII) that contains all the necessary information about the system.
Extension: This use case extends Use Case 2.1: Simple output (old)


Steps:
    1. Create output file.
    2. WHILE devices left
    2.1. Print information about the device to the output file.
    3. WHILE jobs left
    3.1. Print information about the job to the output file.
    4. WHILE climate compensation initiatives left
    4.1. Print information about the initiative to the output file.
    5. Close output file.


Example:
    # === [System Status] === #
    --== Devices ==--
    High-resolution:
    * CO2: 2g/page
    * 12 pages / minute
    * Scanner
    * 60 cents / page
    Office_Groundfloor:
    * CO2: 6g/page
    * 60 pages / minute
    * Black-and-white printer
    * 10 cents / page
    --== Jobs ==--
    [Job #5487]
    * Owner: SergeDemeyer
    * Device: Office_Groundfloor
    * Status: 12 pages done
    * Total pages: 65 pages
    * Total CO2: 390g CO2
    * Total cost: 650 cents
    [Job #345]
    * Owner: User_65643147
    * Device: Office_Groundfloor
    * Status: WAITING #1
    * Total pages: 3 pages
    * Total CO2: 18g CO2
    * Total cost: 30 cents
    * Compensation: The CO2 Reduction Company
    --== Co2 Compensation initiatives ==--
    The CO2 Reduction Company [#78465]
    UN Climate Comittee [#3659]
    # ======================= #


 */


/*
    cout << "__________________________________________________________________" << endl;
    if (report.generateStatusReport(devices, jobs)) {
        cout << "Status report generated successfully." << endl;
        cout << "__________________________________________________________________" << endl;
    } else {
        cerr << "Failed to generate status report." << endl;
        cout << "__________________________________________________________________" << endl;
    }
*/

#include <fstream>
#include <iostream>
#include <vector>
#include "Device.h"
#include "Job.h"
#include "StatusReport.h"

using namespace std;

bool StatusReport::generateStatusReport(vector<Job> jobs) {

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

    for (const auto& device1 : devices) {
        outputFile << "* " << device1.giveDeviceInfo().deviceName << ":" << endl;
        outputFile << "  * CO2: " << device1.giveDeviceInfo().emissions << "g/page" << endl;
        outputFile << "  * " << device1.giveDeviceInfo().speed << " pages / minute" << endl;
        outputFile << "  * " << device1.giveDeviceInfo().deviceType << endl;
        outputFile << "  * " << device1.giveDeviceInfo().costpp << " cents / page" << endl;
        outputFile << endl;
    }

    // Job information
    outputFile << "--== Processed Jobs ==--" << endl;
    outputFile << endl;
    vector<vector<pair<string, vector<Job>>>> tempVector = device.processedJobsVector;
    for (const auto& firstVector : tempVector) {
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
    outputFile << endl;
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