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
#include <string> // Include <string> to use std::string
#include "tinyxml.h"

using namespace std;

// Forward declaration of TiXmlElement to avoid including TinyXML headers in the header file
class TiXmlElement;

// Declare the DeviceInfo struct
struct DeviceInfo {
    string deviceName;
    int emissions;
    int speed;
};
struct JobInfo {
    int jobNumber;
    int pageCount;
    string userName;
};
class XMLReader {
private:
    TiXmlDocument doc;
    vector<DeviceInfo> deviceInfoList;
    vector<JobInfo> jobInfoList;
    bool logerrors = false;

public:
    XMLReader(); // Constructor
    /**
    \n REQUIRE(! this->readerXML(), "Will require a valid filepath. The XML file
needs to contain information about the devices and jobs");
    \n ENSURE(this->readerXML(), "The system contains a printing system with printer devices and printing jobs");
    */
     bool readerXML(string filename);

    const vector<DeviceInfo> &getDeviceInfoList() const { return deviceInfoList; }

    const vector<JobInfo> &getJobInfoList() const { return jobInfoList; }


    void setlogerrors(bool log) { logerrors = log; }
};
#endif // XMLREADER_H