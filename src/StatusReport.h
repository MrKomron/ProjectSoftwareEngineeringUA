//============================================================================
// Name        : StatusReport.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================


//
// This header file would be used to generate a status report of each of the devices and/or jobs.
//
#ifndef TESTFOLDER_STATUSREPORT_H
#define TESTFOLDER_STATUSREPORT_H
#include <iostream>
#include "XMLREADER/XMLReader.h"
#include <string>
#include <vector>

class StatusReport{
public:

    /**
\n REQUIRE(! this->generateStatusReport(), "A valid printing system is loaded.");
\n ENSURE(this->generateStatusReport(), "The system has created a text file (ASCII) that contains all the necessary information about the system");
*/
    static int generateStatusReport(const std::vector<Device>& devices, const std::vector<Job>& jobs);
};
#endif //TESTFOLDER_STATUSREPORT_H
