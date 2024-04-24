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

using namespace std;

class StatusReport{
private:
    bool logerrors = false;
public:

    /**
     * Genereert een statusrapport voor de gegeven apparaten en jobs.
     *
     * REQUIRE(validSystemLoaded(devices, jobs), "Er wordt aangenomen dat een geldig afdruksysteem is geladen (d.w.z. de vector van apparaten en jobs bevat geldige gegevens).");
     * ENSURE(reportCreatedSuccessfully(), "Een tekstbestand (ASCII) is gecreëerd dat alle noodzakelijke informatie over het systeem bevat.");
     */

    bool generateStatusReport(const vector<Device>& devices, const vector<Job>& jobs);
    void setlogerrors(bool log) { logerrors = log; }
};
#endif //TESTFOLDER_STATUSREPORT_H
