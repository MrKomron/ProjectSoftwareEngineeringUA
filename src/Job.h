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
#include <string>
#include <vector>

using namespace std;

class Job {
private:
    int jobNumber;
    int pageCount;
    string userName;
public:
    void setLogerrors(bool logerrors);

private:
    bool logerrors = false;

public:
    /**
     * Constructor die een Job-object initialiseert.
     * @param number Het nummer van de job (standaard 0).
     * @param count Het aantal pagina's van de job (standaard 0).
     * @param name De gebruikersnaam geassocieerd met de job (standaard lege string).
     *
     * @pre Er zijn geen precondities voor deze constructor.
     * @post Het Job-object is gecreëerd met de opgegeven jobnummer, paginatelling en gebruikersnaam.
     */
    Job(int number = 0, int count = 0, const string& name = "");

    /**
     * Vult de lijst met jobs op basis van gegevens van de XMLReader.
     * @param xmlReader De XMLReader met de geladen XML-gegevens.
     *
     * @pre xmlReader moet geïnitialiseerd zijn en een geldige XML-structuur geladen hebben.
     * @post De statische lijst met jobs is gevuld met jobs uit de XMLReader.
     */
    vector<Job> populateFromXMLReader(const XMLReader& xmlReader);
    /**
     * Print de informatie van de job.
     *
     * @pre Het Job-object moet correct geïnitialiseerd zijn.
     * @post Informatie over de job is afgedrukt. Er is geen verandering in de status van het object.
     */
    void printJobInfo() const;
    /**
     * Schrijft de informatie van de job naar een output bestand.
     * @param outputFile De output file stream.
     *
     * @pre outputFile moet open zijn en klaar voor schrijfoperaties.
     * @post Informatie over de job is geschreven naar het outputFile. Er is geen verandering in de status van het object.
     */
    void getJobInfo(ofstream& outputFile) const;
    /**
     * Geeft informatie over de job aan een specifiek apparaat.
     * @param deviceName De naam van het apparaat waarvoor de jobinformatie bestemd is.
     *
     * @pre Het Job-object moet correct geïnitialiseerd zijn.
     * @post Informatie over de job is verstrekt aan het gespecificeerde apparaat. Er is geen verandering in de status van het object.
     */
    void giveJobInfo(const string& deviceName) const;
    /**
    * Geeft het aantal pagina's van de job terug.
    * @return Het aantal pagina's van de job.
    *
    * @pre Het Job-object moet correct geïnitialiseerd zijn.
    * @post Het geretourneerde aantal pagina's is groter dan of gelijk aan 0.
    */
    int getPageCount() const;
    static vector<Job> jobs;
    void setlogerrors(bool log) { logerrors = log; }
};

#endif //TESTFOLDER_JOB_H