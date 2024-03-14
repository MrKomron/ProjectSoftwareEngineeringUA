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
Job::Job(int number, int count, const string& name)
        : jobNumber(number), pageCount(count), userName(name) {}

// Static member function to populate jobs from XMLReader
void Job::populateFromXMLReader(const XMLReader& xmlReader) {
    // Access vectors from XMLReader
    const vector<JobInfo>& jobInfoList = xmlReader.getJobInfoList();
    // Print the size of jobInfoList to verify if it's populated correctly
    cout << "Number of Job entries: " << jobInfoList.size() << endl;
    // Clear any existing jobs before populating new ones
    jobs.clear();
    // Populate Job objects using data from jobInfoList vector
    for (const auto& jobInfo : jobInfoList) {
        Job job(jobInfo.jobNumber, jobInfo.pageCount, jobInfo.userName);
        jobs.push_back(job);
    }
}
// This is a function use to print each one of the contents in the list of Jobs.
void Job::printJobInfo() const {
    cout << "Job Number: " << jobNumber << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "User Name: " << userName << endl;
}
void Job::getJobInfo(ofstream& outputFile) const {
    outputFile << "\t\t[# " << jobNumber << "|" << userName << "]" << endl;
}

void Job::giveJobInfo(const std::string& deviceName) const{
 // This function would be used to print a message in the screen.
 //Example: If a job with 3 pages and job number 13989 was submitted by “John Doe” to the printer “Library Printer 5”, the following message would be printed after the job was finished:
 //Printer "Library Printer 5" finished job:
    //Number: 13989
    //Submitted by "John Doe"
    //3 pages
    cout << "Printer \"" << deviceName << "\" finished job:" << endl;
    cout << "\tNumber: " << jobNumber << endl;
    cout << "\tSubmitted by \"" << userName << "\"" << endl;
    cout << "\t" <<pageCount << " pages" << endl;
}

int Job::getPageCount() const{
    return pageCount;
}


