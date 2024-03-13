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

public:
    XMLReader(); // Constructor
    bool readerXML();
    const std::vector<DeviceInfo>& getDeviceInfoList() const { return deviceInfoList; }
    const std::vector<JobInfo>& getJobInfoList() const { return jobInfoList; }
};
#endif // XMLREADER_H