//============================================================================
// Name        : Device.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================
#ifndef TESTFOLDER_DEVICE_H
#define TESTFOLDER_DEVICE_H
#include <fstream>
#include <iostream>
#include "XMLREADER/XMLReader.h"
#include "Job.h"
#include <string>
#include <vector>

using namespace std;

    /**
     * Constructor die een Device-object initialiseert met een naam, emissies en snelheid.
     *
     * REQUIRE(true, "Er zijn geen precondities voor deze constructor.");
     * ENSURE(this->name == name, "Device naam niet correct geïnitialiseerd.");
     * ENSURE(this->emissions == emissions, "Device emissies niet correct geïnitialiseerd.");
     * ENSURE(this->speed == speed, "Device snelheid niet correct geïnitialiseerd.");
     */

class Device {
private:
    vector<pair<string, vector<Job>>> processedJobs;
    string deviceName;
    int emissions;
    string deviceType;
    int speed;
    bool logerrors = false;
    float cost_per_page;

public:

    // Constructor
    Device(const string &name = "", int emissions = 0, int speed = 0);

    Device(const string& name = "", int emissions = 0, const string& deviceType = "", int speed = 0);
    /**
     * Vult de lijst met apparaten op basis van gegevens van de XMLReader.
     *
     * REQUIRE(xmlReader.isInitialized() && xmlReader.hasValidStructure(), "xmlReader moet geïnitialiseerd zijn en een geldige XML-structuur geladen hebben.");
     * ENSURE(DeviceList::isFilled(), "De statische lijst met apparaten is gevuld met apparaten uit de XMLReader.");
     */


    vector<Device> populateFromXMLReader(const XMLReader &xmlReader);

    /**
      * Print de informatie van het apparaat.
      *
      * REQUIRE(this->isInitialized(), "Het Device-object moet correct geïnitialiseerd zijn.");
      * ENSURE(noChangeInState(), "Informatie over het apparaat is afgedrukt. Er is geen verandering in de status van het object.");
      */


    void printDeviceInfo() const;

    /**
     * Schrijft de informatie van het apparaat naar een output bestand.
     *
     * REQUIRE(outputFile.isOpen() && outputFile.isReadyForWriting(), "outputFile moet open zijn en klaar voor schrijfoperaties.");
     * ENSURE(informationWritten(outputFile) && noChangeInState(), "Informatie over het apparaat is geschreven naar het outputFile. Er is geen verandering in de status van het object.");
     */


    void getDeviceInfo(ofstream &outputFile) const;

    /**
     * Geeft de naam van het apparaat terug.
     *
     * REQUIRE(this->isInitialized(), "Het Device-object moet correct geïnitialiseerd zijn.");
     * ENSURE(!this->getName().empty(), "De naam van het apparaat is niet leeg.");
     */

    DeviceInfo giveDeviceInfo() const;

    string getDeviceName() const;

    static vector<Device> devices;

    void setlogerrors(bool log) { logerrors = log; }

    float getCostPerPage() const;
    bool manualProcess(const string& selectedDeviceName, const int selectedJobNumber, vector<Job>& jobs);
};

#endif //TESTFOLDER_DEVICE_H