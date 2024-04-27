//============================================================================
// Name        : StatusReport.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================


//
// This header file would be used to generate a status report.
// The StatusReport class generates a status report for the printing system, including information about the devices and jobs.
//

#include <iostream>
#include <vector>
#include "Device.h"
#include "Job.h"

class StatusReport {
private:
    bool logerrors = false;

public:

    bool generateStatusReport(const vector<Device> &devices, const vector<Job> &jobs);

    void setlogerrors(bool log) { logerrors = log; }
};