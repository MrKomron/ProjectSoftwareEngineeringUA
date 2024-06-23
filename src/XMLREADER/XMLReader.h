//============================================================================
// Name        : XMLReader.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================

#ifndef XMLREADER_H
#define XMLREADER_H

#include <vector>
#include <string>
#include "tinyxml.h"
#include "../DesignByContract.h"

using namespace std;

// Forward declaration of TiXmlElement to avoid including TinyXML headers in the header file
class TiXmlElement;

// Declare the DeviceInfo struct
struct DeviceInfo {
    string deviceName;
    int emissions;
    string deviceType;
    int speed;
    int costpp;
    int accumulatedPages;
    int totalEmissions;
    int totalEarnings;
};
struct JobInfo {
    int jobNumber;
    int pageCount;
    string jobType;
    string userName;
    int totalCost;
    int totalEmissions;
};
class XMLReader {
private:
    TiXmlDocument doc;
    vector<DeviceInfo> deviceInfoList;
    vector<JobInfo> jobInfoList;

    XMLReader* _initCheck; //!use pointer to myself to verify whether I am properly initialized

public:
    /**
    \n ENSURE(properlyInitialized(), "Constructor must end in properlyInitialized state");
    */
    XMLReader(); // Constructor

    /**
      * Leest en verwerkt een XML-bestand.
      *
      * \n REQUIRE(!filename.empty(), "Filename must not be empty");
      * \n REQUIRE(properlyInitialized(), "XMLReader wasn't properly initialized when calling readerXML");
      * \n ENSURE(result == true || result == false, "readerXML must return a boolean indicating success or failure");
      * \n ENSURE((result && !deviceInfoList.empty() && !jobInfoList.empty()) || !result, "If readerXML is successful, deviceInfoList and jobInfoList must be populated");
      *
      * @param filename De naam van het XML-bestand dat moet worden gelezen.
      * @return Een boolean die aangeeft of het lezen succesvol was.
      *
      * @pre Er moet een geldig XML-bestand op het opgegeven pad bestaan dat informatie bevat over apparaten en taken.
      * @post Indien succesvol, bevat `deviceInfoList` informatie over de apparaten en `jobInfoList` informatie over de taken.
      */
     bool readerXML(string filename);

    /**
    * Returns the list of device information.
    * \n REQUIRE(properlyInitialized(), "XMLReader wasn't properly initialized when calling getDeviceInfoList");
    * @return A constant reference to the device info list.
    */
     const vector<DeviceInfo> &getDeviceInfoList() const { return deviceInfoList; }

    /**
    * Returns the list of job information.
    * \n REQUIRE(properlyInitialized(), "XMLReader wasn't properly initialized when calling getJobInfoList");
    * @return A constant reference to the job info list.
    */
     const vector<JobInfo> &getJobInfoList() const { return jobInfoList; }

    /**
    * Checks if the XMLReader is properly initialized.
    * @return true if properly initialized, otherwise false.
    */
    bool properlyInitialized() const { return _initCheck == this; }
    //    bool properlyInitialized() const;
};
#endif // XMLREADER_H