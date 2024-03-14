//============================================================================
// Name        : Job.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================
#ifndef TESTFOLDER_JOB_H
#define TESTFOLDER_JOB_H
#include <fstream>
#include <iostream>
#include "XMLREADER/XMLReader.h"
#include <string>
#include <vector>

class Job {
private:
    int jobNumber;
    int pageCount;
    std::string userName;

public:
    // Constructor
    Job(int number = 0, int count = 0, const std::string& name = "");

    // Function to populate jobs from XMLReader
    static void populateFromXMLReader(const XMLReader& xmlReader);
    void printJobInfo() const;
    void getJobInfo(std::ofstream& outputFile) const;
    void giveJobInfo(const std::string& deviceName) const;
    static std::vector<Job> jobs;
    int getPageCount() const;
};

#endif //TESTFOLDER_JOB_H