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
vector<Job> Job::jobs;
Job::Job(int number, int count, const string& jobType, const string& name, int totalCost)
        : jobNumber(number), pageCount(count), jobType(jobType), userName(name) {}
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
        Job job(jobInfo.jobNumber, jobInfo.pageCount, jobInfo.jobType, jobInfo.userName);
        jobs.push_back(job);
    }
    return jobs;
}
// This is a function use to print each one of the contents in the list of Jobs.
void Job::printJobInfo() const {
    if (logerrors) cout << "Job Number: " << jobNumber << endl;
    if (logerrors) cout << "Page Count: " << pageCount << endl;
    if (logerrors) cout << "Type: " << jobType << endl;
    if (logerrors) cout << "User Name: " << userName << endl;
}

JobInfo Job::giveJobInfo() const {
    JobInfo info;
    info.jobNumber = jobNumber;
    info.pageCount = pageCount;
    info.jobType = jobType;
    info.userName = userName;
    return info;
}

int Job::getPageCount() const{
    return pageCount;
}

float Job::getCost() const {
    return totalCost;
}

int Job::calculateCost() {
    return totalCost=7777;
}

Job::Job(int jobId, Device* device)
        : jobId(jobId), device(device), emissions(0) {}

double Job::execute() {
    if (device) {
        emissions = device->getEmissionsPerUnit();  // Bereken de emissies
        std::cout << "Job " << jobId << " executed with emissions: " << emissions << std::endl;
        return emissions;
    }
    return 0;
}

double Job::getEmissions() const {
    return emissions;
}