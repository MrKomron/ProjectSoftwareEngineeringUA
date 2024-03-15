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

int System::manualProcess(std::vector<Device>& devices, std::vector<Job>& jobs){
    if (jobs.empty()) {
        cerr << "No jobs to process." << std::endl;
        return 1; // Return an error code indicating no jobs to process
    }
    // Process the first job in the job list
    const Job& firstJob = jobs.front();
    if (!devices.empty()) {
        int printedPages = 0;
        int pageCount = firstJob.getPageCount();
        while (printedPages < pageCount) {
            ++printedPages; // Increment printed pages
            cout << "Printed pages: " << printedPages << endl;

            // Check if all pages have been printed
            if (printedPages == pageCount) {
                cout << "All pages printed." << endl;
                break; // Exit the loop
            }
        }

        // Assuming devices vector is not empty
        const string& deviceName = devices.front().getDeviceName();
        // Call giveJobInfo() with the device name
        firstJob.giveJobInfo(deviceName);

    } else {
        cerr << "No devices available. Cancelling the process" << endl;
        return 1;
    }
    // Remove the first job so that the next job would be ready to be process
    jobs.erase(jobs.begin());
    // Additional processing logic for the first job can be added here

    return 0;
}
//
//int System::automatedProcess(std::vector<Device>& devices, std::vector<Job>& jobs) {
//    if (jobs.empty()) {
//        // If the list of jobs is empty
//        cout << "No jobs to perform." << endl;
//        return 1; // Return an error code indicating no jobs to perform
//    } else {
//        // Perform manual processing on each job in the list
//        for (auto& job : jobs) {
//            int result = manualProcess(devices, jobs);
//            if (result != 0) {
//                // If manual processing encounters an error, return immediately
//                cerr << "Error processing job." << endl;
//                return result;
//            }
//        }
//        // All jobs processed successfully
//        cout << "All jobs processed successfully." << endl;
//        return 0;
//    }
//}