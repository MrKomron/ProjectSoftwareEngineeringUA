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
    if (logerrors) cout << "Number of Job entries: " << jobInfoList.size() << endl;
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
    if (logerrors) cout << "Job Number: " << jobNumber << endl;
    if (logerrors) cout << "Page Count: " << pageCount << endl;
    if (logerrors) cout << "Type: " << jobType << endl;
    if (logerrors) cout << "User Name: " << userName << endl;
    if (logerrors) cout << "TotalCost: " << totalCost << endl;
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


