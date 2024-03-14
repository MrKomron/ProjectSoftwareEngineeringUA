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
public:
    static int manualProcess(std::vector<Device>& devices, std::vector<Job>& jobs);
//    static int automatedProcess(std::vector<Device>& devices, std::vector<Job>& jobs);
//    int automatedProcess(std::vector<Device>& devices, std::vector<Job>& jobs);

};

#endif //TESTFOLDER_SYSTEMPROCESSING_H
