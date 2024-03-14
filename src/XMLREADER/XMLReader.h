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

// Forward declaration of TiXmlElement to avoid including TinyXML headers in the header file
class TiXmlElement;

// Declare the DeviceInfo struct
struct DeviceInfo {
    std::string deviceName;
    int emissions;
    int speed;
};
struct JobInfo {
    int jobNumber;
    int pageCount;
    std:: string userName;
};
class XMLReader {
private:
    TiXmlDocument doc;
    std::vector<DeviceInfo> deviceInfoList;
    std::vector<JobInfo> jobInfoList;
    bool logerrors = false;

public:
    XMLReader(); // Constructor
    bool readerXML(std::string filename);
    const std::vector<DeviceInfo>& getDeviceInfoList() const { return deviceInfoList; }
    const std::vector<JobInfo>& getJobInfoList() const { return jobInfoList; }
    void setlogerrors(bool log) { logerrors = log; }
};
#endif // XMLREADER_H