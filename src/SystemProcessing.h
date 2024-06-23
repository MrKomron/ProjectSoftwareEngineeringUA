//============================================================================
// Name        : SystemProcessing.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declaration of the SystemProcessing class in C++
//============================================================================

#ifndef SYSTEMPROCESSING_H
#define SYSTEMPROCESSING_H

#include <iostream>
#include <string>
#include <vector>
#include "XMLREADER/XMLReader.h"
#include "Device.h"
#include "Job.h"

using namespace std;

class System{
private:
    ofstream outFile; // Output file stream for standard output
    ofstream errFile; // Output file stream for standard errors
    streambuf* coutBuf; // Save old buffer for cout
    streambuf* cerrBuf; // Save old buffer for cerr

    /**
     * Restores the standard input/output streams from the files.
     *
     * \n ENSURE(true, "Standard input/output streams are restored from the files.");
     */
    void restoreIOFromFiles();

    /**
     * Redirects standard error stream to a file.
     *
     * \n ENSURE(true, "Standard error stream is redirected to a file.");
     */
    void redirectIOToFilesError();

    /**
     * Redirects standard output stream to a file.
     *
     * \n ENSURE(true, "Standard output stream is redirected to a file.");
     */
    void redirectIOToFilesOutput();

public:
    System() : coutBuf(cout.rdbuf()), cerrBuf(cerr.rdbuf()) {}

    /**
     * Redirects input/output streams to files if enabled.
     *
     * \n REQUIRE(true, "There are no preconditions for this function.");
     * \n ENSURE((!enable || (enableOutput && enableError)), "IO streams are either not redirected or redirected to the specified files.");
     */
    void redirectIOToFiles(bool enable, bool enableOutput, bool enableError);

    /**
     * Schedules a job manually for a specific device.
     *
     * \n REQUIRE(!deviceName.empty(), "Device name must not be empty.");
     * \n REQUIRE(jobNumber >= 0, "Job number must be non-negative.");
     * \n ENSURE(result == true || result == false, "Job scheduling is completed, returns true if successful, otherwise false.");
     */
    bool schedulerManual(const string& deviceName, int jobNumber, vector<Job>& jobs);

    /**
     * Schedules jobs automatically based on the type of devices and jobs available.
     *
     * \n REQUIRE(!devices1.empty(), "Device list must not be empty.");
     * \n REQUIRE(!jobs.empty(), "Job list must not be empty.");
     * \n ENSURE(true, "Jobs are scheduled automatically.");
     */
    bool schedulerAutomated(vector<Device>& devices1, vector<Job>& jobs);

    static vector<Device> tempBW;
    static vector<Device> tempCOLOR;
    static vector<Device> tempSCAN;
};

#endif //TESTFOLDER_SYSTEMPROCESSING_H