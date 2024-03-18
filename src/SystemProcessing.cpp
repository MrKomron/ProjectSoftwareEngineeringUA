//============================================================================
// Name        : SystemProcessing.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================

#include <iostream>
#include <vector>
#include "Device.h"
#include "Job.h"
#include "SystemProcessing.h"

using namespace std;

bool System::manualProcess(vector<Device>& devices, vector<Job>& jobs){
    if (jobs.empty()) {
        if (logerrors) cerr << "No jobs to process." << std::endl;
        return false; // Return an error code indicating no jobs to process
    }
    // Process the first job in the job list
    const Job& firstJob = jobs.front();
    if (!devices.empty()) {
        int printedPages = 0;
        int pageCount = firstJob.getPageCount();
        while (printedPages < pageCount) {
            ++printedPages; // Increment printed pages
            if (logerrors) cout << "Printed pages: " << printedPages << endl;

            // Check if all pages have been printed
            if (printedPages == pageCount) {
                if (logerrors) cout << "All pages printed." << endl;
                break; // Exit the loop
            }
        }

        // Assuming devices vector is not empty
        const string& deviceName = devices.front().getDeviceName();
        // Call giveJobInfo() with the device name
        firstJob.giveJobInfo(deviceName);

    } else {
        if (logerrors) cerr << "No devices available. Cancelling the process" << endl;
        return false;
    }
    // Remove the first job so that the next job would be ready to be process
    jobs.erase(jobs.begin());
    // Additional processing logic for the first job can be added here
    return true;
}
//
bool System::automatedProcess(vector<Device>& devices, vector<Job>& jobs) {
    while (!jobs.empty()) {
        bool result = manualProcess(devices, jobs);
        if (!result) {
            // All jobs processed successfully
            if (logerrors) cout << "All jobs processed successfully." << endl;
            break;
        }
    }
    return true;
}