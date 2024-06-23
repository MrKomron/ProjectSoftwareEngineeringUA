//============================================================================
// Name        : Job.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================

#ifndef JOB_H
#define JOB_H

#include <fstream>
#include <iostream>
#include "XMLREADER/XMLReader.h"
#include <string>
#include <vector>

using namespace std;

class Job {
private:
    int jobNumber;
    int pageCount;
    string jobType;
    string userName;
    int totalCost = 0;
    int totalEmissions;

public:


    /**
     * Constructor die een Job-object initialiseert met specifieke eigenschappen.
     *
     * \n REQUIRE(true, "Er zijn geen precondities voor deze constructor.");
     * \n ENSURE(this->jobNumber == jobNumber, "Job number not correctly initialized.");
     * \n ENSURE(this->pageCount == pageCount, "Page count not correctly initialized.");
     * \n ENSURE(this->jobType == jobType, "Job type not correctly initialized.");
     * \n ENSURE(this->userName == userName, "User name not correctly initialized.");
     * \n ENSURE(this->totalCost == totalCost, "Total cost not correctly initialized.");
     */
    // Job(int jobNumber = 0, int pageCount = 0, const string& jobType = "", const string& userName = "", int totalCost = 0);
    explicit Job(int jobNumber = 0, int pageCount = 0, const string& jobType = "", const string& userName = "", int totalCost = 0, int totalEmissions =0);

    /**
     * Populates the list of jobs based on data from the XMLReader.
     *
     * \n REQUIRE(xmlReader.properlyInitialized(), "xmlReader must be properly initialized and contain a valid XML structure.");
     * \n ENSURE(!jobs.empty(), "The job list is populated with jobs from the XMLReader.");
     */
    vector<Job> populateFromXMLReader(const XMLReader& xmlReader);

    /**
     * Prints the job information.
     *
     * \n REQUIRE(properlyInitialized(), "The Job object must be properly initialized.");
     * \n ENSURE(true, "Job information is printed. No change in the state of the object.");
     */
    void printJobInfo() const;

    /**
     * Returns the job information.
     *
     * ??? REQUIRE(outputFile.isOpen() && outputFile.isReadyForWriting(), "outputFile moet open zijn en klaar voor schrijfoperaties.");
     * \n ENSURE(!userName.empty(), "The job information is correctly returned.");
     */
    JobInfo giveJobInfo() const;

    /**
     * Prints the list of jobs.
     *
     * \n REQUIRE(!jobs.empty(), "The job list must not be empty.");
     * \n ENSURE(true, "Job list information is printed. No change in the state of the objects.");
     */
    void printJobList(vector<Job> jobs);

    /**
     * Writes the job information to an output file.
     *
     * \n REQUIRE(!jobList.empty(), "The job list must not be empty.");
     * \n REQUIRE(!fileName.empty(), "The file name must not be empty.");
     * \n ENSURE(true, "Job information is written to the file. No change in the state of the objects.");
     */
    void writeJobListOutputToFile(vector<Job>& jobList, string& fileName);

    /**
     * Sets the new total cost for the job.
     *
     * \n REQUIRE(newTotalCost >= 0, "New total cost must be non-negative.");
     * \n ENSURE(this->totalCost == newTotalCost, "Total cost is correctly updated.");
     */
    void setNewTotalCost(int newTotalCost) { totalCost = newTotalCost; }

    // Getters

    void set_total_emmisions(int total_emmisions)
    {
     totalEmissions = total_emmisions;
    }

    // Getter functions
    int getJobNumber() const { return jobNumber; }
    int getPageCount() const { return pageCount; }
    int getTotalCost() const { return totalCost; }
    const string& getJobType() const { return jobType; }
    const string& getUserName() const { return userName; }

    static vector<Job> jobs;

};

#endif //TESTFOLDER_JOB_H