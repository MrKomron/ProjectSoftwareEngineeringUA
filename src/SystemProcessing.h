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

class System{
private:

public:
    bool schedulerManual(const string& deviceName, int jobNumber, const vector<Device>& device, vector<Job>& jobs);
    bool schedulerAutomated(vector<Device>& devices1, vector<Job>& jobs);
    static vector<vector<Device>> tempBW;
    static vector<vector<Device>> tempCOLOR;
    static vector<vector<Device>> tempSCAN;
};

#endif //TESTFOLDER_SYSTEMPROCESSING_H