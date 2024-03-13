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
    static int generateStatusReport(const std::vector<Device>& devices, const std::vector<Job>& jobs);
};
#endif //TESTFOLDER_STATUSREPORT_H
