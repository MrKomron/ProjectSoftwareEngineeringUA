//============================================================================
// Name        : StatusReport.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================


// This source file would be used to generate a status report of each of the devices and/or jobs.
// The functions from this would be accessible from main to either print out the status of the device or the job.
#include <fstream>
#include <iostream>
#include <vector>
#include "Device.h"
#include "Job.h"
#include "StatusReport.h"

using namespace std;

int StatusReport::generateStatusReport(const vector<Device>& devices, const vector<Job>& jobs) {
    // Create a text file and open it in write mode.
    ofstream outputFile("status_report.txt");
    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return 1; // Return non-zero to indicate failure
    }
    else if (outputFile.is_open()) {
        cout << "Successfully opened output file." << endl;
        cout<< endl;
    }
    bool foundDevice = false;
    // Generate status report for devices
    for (const auto& device : devices) {
        device.getDeviceInfo(outputFile);
        foundDevice = true;
    }
    if (!foundDevice) {
        outputFile << "No device available at the moment." << endl;
        return 1;
    }
    // Process first job separately
    if (!jobs.empty() || jobs.size() == 1) {
        outputFile << "\t* Current:" << endl;
        jobs.front().getJobInfo(outputFile);
    }
    // Print job queue information
    if (jobs.size() > 1) {
        outputFile << "\t* Queue:" << endl;
        for (size_t i = 1; i < jobs.size(); ++i) { // Start from the second job
            const Job& queuedJob = jobs[i];
            queuedJob.getJobInfo(outputFile);
        }
    }
    else {
        outputFile << "\t* Queue:" << endl;
        outputFile << "\t\t[There is no more job in the queue.]" << endl;
    }

    outputFile.close();
    return 0;
}
