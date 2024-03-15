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
public:

/**
     * Genereert een statusrapport voor de gegeven apparaten en jobs.
     * @param devices Een vector van Device-objecten.
     * @param jobs Een vector van Job-objecten.
     *
     * @pre Er wordt aangenomen dat een geldig afdruksysteem is geladen (d.w.z. de vector van apparaten en jobs bevat geldige gegevens).
     * @post Een tekstbestand (ASCII) is gecreëerd dat alle noodzakelijke informatie over het systeem bevat.
     *
     * @return Een integer waarde die de status van het rapportgeneratieproces aangeeft (bijvoorbeeld 0 voor succes).
     */
    static int generateStatusReport(const vector<Device>& devices, const vector<Job>& jobs);
};
#endif //TESTFOLDER_STATUSREPORT_H
