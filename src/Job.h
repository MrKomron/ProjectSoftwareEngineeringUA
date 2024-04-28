//============================================================================
// Name        : Job.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================
#ifndef TESTFOLDER_JOB_H
#define TESTFOLDER_JOB_H
#include <fstream>
#include <iostream>
#include "XMLREADER/XMLReader.h"
#include "Device.h"
#include <string>
#include <vector>

using namespace std;

class Job {
private:
    int jobNumber;
    int pageCount;
    string jobType;
    string userName;
    bool logerrors = false;
    int totalCost;
    double emissions;
    int jobId;
    Device* device;

public:

    Job(int jobId, Device* device);
    double execute();
    double getEmissions() const;

    void setLogerrors(bool logerrors);

    /**
     * Constructor die een Job-object initialiseert met specifieke eigenschappen.
     *
     * REQUIRE(true, "Er zijn geen precondities voor deze constructor.");
     * ENSURE(this->number == 0, "Job nummer niet correct geïnitialiseerd.");
     * ENSURE(this->count == 0, "Paginatelling niet correct geïnitialiseerd.");
     * ENSURE(this->name.empty(), "Gebruikersnaam niet correct geïnitialiseerd als lege string.");
     */

    Job(int jobNumber = 0, int pageCount = 0, const string& jobType = "", const string& userName = "", int totalCost = 0);

    /**
     * Vult de lijst met jobs op basis van gegevens van de XMLReader.
     *
     * REQUIRE(xmlReader.isInitialized() && xmlReader.hasValidStructure(), "xmlReader moet geïnitialiseerd zijn en een geldige XML-structuur geladen hebben.");
     * ENSURE(JobList::isFilled(), "De statische lijst met jobs is gevuld met jobs uit de XMLReader.");
     */

    vector<Job> populateFromXMLReader(const XMLReader& xmlReader);
    /**
     * Print de informatie van de job.
     *
     * REQUIRE(this->isInitialized(), "Het Job-object moet correct geïnitialiseerd zijn.");
     * ENSURE(noChangeInState(), "Informatie over de job is afgedrukt. Er is geen verandering in de status van het object.");
     */

    void printJobInfo() const;
    /**
     * Schrijft de informatie van de job naar een output bestand.
     *
     * REQUIRE(outputFile.isOpen() && outputFile.isReadyForWriting(), "outputFile moet open zijn en klaar voor schrijfoperaties.");
     * ENSURE(informationWritten(outputFile) && noChangeInState(), "Informatie over de job is geschreven naar het outputFile. Er is geen verandering in de status van het object.");
     */

    void getJobInfo(ofstream& outputFile) const;
    /**
     * Geeft informatie over de job aan een specifiek apparaat.
     *
     * REQUIRE(this->isInitialized(), "Het Job-object moet correct geïnitialiseerd zijn.");
     * ENSURE(informationProvidedTo(deviceName) && noChangeInState(), "Informatie over de job is verstrekt aan het gespecificeerde apparaat. Er is geen verandering in de status van het object.");
     */

    void giveJobInfo(const string& deviceName) const;

    JobInfo giveJobInfo() const;
    /**
     * Geeft het aantal pagina's van de job terug.
     *
     * REQUIRE(this->isInitialized(), "Het Job-object moet correct geïnitialiseerd zijn.");
     * ENSURE(result >= 0, "Het geretourneerde aantal pagina's is groter dan of gelijk aan 0.");
     */

    int getPageCount() const;
    static vector<Job> jobs;
    void setlogerrors(bool log) { logerrors = log; }

    float getCost() const;

    int calculateCost();

};

#endif //TESTFOLDER_JOB_H