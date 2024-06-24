//============================================================================
// Name        : Job.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Implementation of the Job class in C++
//============================================================================

#include <fstream>
#include <iostream>
#include "Job.h"

#include <algorithm>

#include "loggerClass.h"
#include "XMLREADER/XMLReader.h"

using namespace std;

Job::Job(int number, int count, const string& jobType, const string& name, int totalCost, int totalEmissions)
        : jobNumber(number), pageCount(count), jobType(jobType), userName(name), totalCost(totalCost),  totalEmissions(totalEmissions){
    ENSURE(this->jobNumber == number, "Job number not correctly initialized.");
    ENSURE(this->pageCount == count, "Page count not correctly initialized.");
    ENSURE(this->jobType == jobType, "Job type not correctly initialized.");
    ENSURE(this->userName == name, "User name not correctly initialized.");
    ENSURE(this->totalCost == totalCost, "Total cost not correctly initialized.");
    ENSURE(this->totalEmissions == totalEmissions, "Total emissions not correctly initialized.");
}

vector<Job> Job::jobs;

// Static member function to populate jobs from XMLReader
vector<Job> Job::populateFromXMLReader(const XMLReader& xmlReader) {
    REQUIRE(xmlReader.properlyInitialized(), "xmlReader must be properly initialized and contain a valid XML structure.");

    // Access vectors from XMLReader
    const vector<JobInfo>& jobInfoList = xmlReader.getJobInfoList();
    // Print the size of jobInfoList to verify if it's populated correctly

    // cout << "Number of Job entries: " << jobInfoList.size() << endl;
    outputPrinter::numberEntriesJob(jobInfoList.size());
    // Clear any existing jobs before populating new ones
    jobs.clear();

    // Populate Job objects using data from jobInfoList vector
    for (const auto& jobInfo : jobInfoList) {
        Job job1(jobInfo.jobNumber, jobInfo.pageCount, jobInfo.jobType, jobInfo.userName, jobInfo.totalCost, jobInfo.totalEmissions);
        jobs.push_back(job1);
    }

    //ENSURE(!jobs.empty(), "The job list is populated with jobs from the XMLReader.");
    return jobs;
}

// This is a function use to print each one of the contents in the list of Jobs.
void Job::printJobInfo() const {
    REQUIRE(true, "There are no preconditions for this function.");
    outputPrinter::printerInfoJob(jobNumber, pageCount, jobType, userName, totalCost, totalEmissions);
    // cout << "Job Number: " << jobNumber << endl;
    // cout << "Page Count: " << pageCount << endl;
    // cout << "Job Type: " << jobType << endl;
    // cout << "User Name: " << userName << endl;
    // cout << "Total Cost: " << totalCost << endl;
    ENSURE(true, "Job information is printed. No change in the state of the object.");
}

JobInfo Job::giveJobInfo() const {
    REQUIRE(true, "There are no preconditions for this function.");

    JobInfo info;
    info.jobNumber = jobNumber;
    info.pageCount = pageCount;
    info.jobType = jobType;
    info.userName = userName;
    info.totalCost = totalCost;

    ENSURE(!info.userName.empty(), "The job information is correctly returned.");
    return info;
}

void Job::printJobList(vector<Job> jobList) {
    //REQUIRE(!jobList.empty(), "The job list must not be empty.");

    for (auto &job : jobList){
        job.printJobInfo();
    }

    ENSURE(true, "Job list information is printed. No change in the state of the objects.");
}

void Job::writeJobListOutputToFile(vector<Job>& jobList, string& fileName) {
    //++++++REQUIRE(!jobList.empty(), "The job list must not be empty.");
    REQUIRE(!fileName.empty(), "The file name must not be empty.");

    ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << "Number of Job entries: " << jobList.size() << "\n";
        for (const auto& job : jobList) {
            outFile << "Job Number: " << job.getJobNumber() << "\n";
            outFile << "Page Count: " << job.getPageCount() << "\n";
            outFile << "Job Type: " << job.getJobType() << "\n";
            outFile << "User Name: " << job.getUserName() << "\n";
            outFile << "Total Cost: " << job.getTotalCost() << "\n";
        }
        outFile.close();
    }

    ENSURE(true, "Job information is written to the file. No change in the state of the objects.");
}