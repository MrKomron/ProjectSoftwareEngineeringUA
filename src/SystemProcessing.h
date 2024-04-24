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
    bool logerrors = false;
public:
    bool scheduler(const string& deviceName, int jobNumber, const vector<Device>& device, vector<Job>& jobs, const char logerror);
    void setlogerrors(bool log) { logerrors = log; }

};

#endif //TESTFOLDER_SYSTEMPROCESSING_H