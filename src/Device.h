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
#include <string>
#include <vector>

using namespace std;
/**
 * Constructor die een Device-object initialiseert.
 * @param name De naam van het apparaat (standaard lege string).
 * @param emissions De emissies van het apparaat (standaard 0).
 * @param speed De snelheid van het apparaat (standaard 0).
 *
 * @pre Er zijn geen precondities voor deze constructor.
 * @post Het Device-object is gecreëerd met de opgegeven naam, emissies en snelheid.
 */
class Device {
private:
    string deviceName;
    int emissions;
    int speed;
    bool logerrors = false;

public:
    // Constructor
    Device(const string& name = "", int emissions = 0, int speed = 0);
    /**
     * Vult de lijst met apparaten op basis van gegevens van de XMLReader.
     * @param xmlReader De XMLReader met de geladen XML-gegevens.
     *
     * @pre xmlReader moet geïnitialiseerd zijn en een geldige XML-structuur geladen hebben.
     * @post De statische lijst met apparaten is gevuld met apparaten uit de XMLReader.
     */

    vector<Device> populateFromXMLReader(const XMLReader& xmlReader);
    /**
     * Print de informatie van het apparaat.
     *
     * @pre Het Device-object moet correct geïnitialiseerd zijn.
     * @post Informatie over het apparaat is afgedrukt. Er is geen verandering in de status van het object.
     */

    void printDeviceInfo() const;
    /**
     * Schrijft de informatie van het apparaat naar een output bestand.
     * @param outputFile De output file stream.
     *
     * @pre outputFile moet open zijn en klaar voor schrijfoperaties.
     * @post Informatie over het apparaat is geschreven naar het outputFile. Er is geen verandering in de status van het object.
     */

    void getDeviceInfo(ofstream& outputFile) const;
    /**
     * Geeft de naam van het apparaat terug.
     * @return De naam van het apparaat.
     *
     * @pre Het Device-object moet correct geïnitialiseerd zijn.
     * @post De naam van het apparaat is niet leeg.
     */

    string getDeviceName() const;
    static vector<Device> devices;
    void setlogerrors(bool log) { logerrors = log; }
};

#endif //TESTFOLDER_DEVICE_H