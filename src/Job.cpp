//============================================================================
// Name        : Job.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================
#include <fstream>
#include <iostream>
#include "Job.h"

#include <algorithm>

#include "loggerClass.h"
#include "XMLREADER/XMLReader.h"

using namespace std;
Job::Job(int number, int count, const string& jobType, const string& name, int totalCost)
        : jobNumber(number), pageCount(count), jobType(jobType), userName(name), totalCost(totalCost){}

vector<Job> Job::jobs;
// Static member function to populate jobs from XMLReader
vector<Job> Job::populateFromXMLReader(const XMLReader& xmlReader) {
    // Access vectors from XMLReader
    const vector<JobInfo>& jobInfoList = xmlReader.getJobInfoList();
    // Print the size of jobInfoList to verify if it's populated correctly
    cout << "Number of Job entries: " << jobInfoList.size() << endl;
    // Clear any existing jobs before populating new ones
    jobs.clear();
    // Populate Job objects using data from jobInfoList vector
    for (const auto& jobInfo : jobInfoList) {
        Job job1(jobInfo.jobNumber, jobInfo.pageCount, jobInfo.jobType, jobInfo.userName, jobInfo.totalCost);
        jobs.push_back(job1);
    }
    return jobs;
}
// This is a function use to print each one of the contents in the list of Jobs.
void Job::printJobInfo() const {
    cout << "Job Number: " << jobNumber << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "Job Type: " << jobType << endl;
    cout << "User Name: " << userName << endl;
    cout << "Total Cost: " << totalCost << endl;
}

JobInfo Job::giveJobInfo() const {
    JobInfo info;
    info.jobNumber = jobNumber;
    info.pageCount = pageCount;
    info.jobType = jobType;
    info.userName = userName;
    info.totalCost = totalCost;
    return info;
}
void Job::printJobList(vector<Job> jobList) {
    for (auto &job : jobList){
        job.printJobInfo();
    }
}
void Job::writeJobListOutputToFile(vector<Job>& jobList, string& fileName) {
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
}