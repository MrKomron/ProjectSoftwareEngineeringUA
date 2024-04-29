//============================================================================
// Name        : SystemProcessing.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================

#ifndef TESTFOLDER_SYSTEMPROCESSING_H
#define TESTFOLDER_SYSTEMPROCESSING_H
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
    void restoreIOFromFiles();
    void redirectIOToFilesError();
    void redirectIOToFilesOutput();
public:
    System() : coutBuf(cout.rdbuf()), cerrBuf(cerr.rdbuf()) {}
    void redirectIOToFiles(bool enable, bool enableOutput, bool enableError);
    bool schedulerManual(const string& deviceName, int jobNumber, vector<Job>& jobs);
    bool schedulerAutomated(vector<Device>& devices1, vector<Job>& jobs);
    static vector<Device> tempBW;
    static vector<Device> tempCOLOR;
    static vector<Device> tempSCAN;
};

#endif //TESTFOLDER_SYSTEMPROCESSING_H