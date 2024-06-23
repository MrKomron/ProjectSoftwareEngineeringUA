//============================================================================
// Name        : Device.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================
//
#ifndef DEVICE_H
#define DEVICE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "XMLREADER/XMLReader.h"
#include "Job.h"
#include "DesignByContract.h"

using namespace std;


class Device {
private:
    string deviceName;
    int emissions;
    string deviceType;
    int speed;
    int cost_per_page;
    int accumulatedPages;
    int totalEmissions;
    int totalEarnings;

    //Device* _initCheck; //!use pointer to myself to verify whether I am properly initialized

public:
    static vector<Device>* getDevicesBW();
    static vector<Device>* getDevicesCOLOR();
    static vector<Device>* getDevicesSCAN();

    bool operator==(const Device& other) const {
        return deviceName == other.deviceName && deviceType == other.deviceType;
    }
    static bool compareByAccuPages(const Device& a, const Device& b) {
        return a.accumulatedPages < b.accumulatedPages;
    }
    // Constructor
    // Device(const string &name = "", int emissions = 0, int speed = 0, float cost_per_page = 0);

    /**
     * Constructor that initializes a Device object with a name, emissions, type, speed, cost per page, and accumulated pages.
     *
     * \n REQUIRE(true, "There are no preconditions for this constructor.");
     * \n ENSURE(this->deviceName == name, "Device name not correctly initialized.");
     * \n ENSURE(this->emissions == emissions, "Device emissions not correctly initialized.");
     * \n ENSURE(this->deviceType == deviceType, "Device type not correctly initialized.");
     * \n ENSURE(this->speed == speed, "Device speed not correctly initialized.");
     * \n ENSURE(this->cost_per_page == cost_per_page, "Device cost per page not correctly initialized.");
     * \n ENSURE(this->accumulatedPages == accumulatedPages, "Device accumulated pages not correctly initialized.");
     */
    Device(const string& name = "", int emissions = 0, const string& deviceType = "", int speed = 0, int cost_per_page = 0,
         int accumulatedPages = 0, int totalEmissions = 0, int totalEarnings = 0):
         deviceName(name), emissions(emissions), deviceType(deviceType), speed(speed), cost_per_page(cost_per_page),
         accumulatedPages(accumulatedPages), totalEmissions(totalEmissions),
         totalEarnings(totalEarnings) {}

    /**
     * Populates the device list based on data from the XMLReader.
     *
     * \n REQUIRE(xmlReader.properlyInitialized(), "xmlReader must be properly initialized and contain a valid XML structure.");
     * \n ENSURE(!devices.empty(), "The device list is populated with devices from the XMLReader.");
     */
    vector<Device> populateFromXMLReader(const XMLReader &xmlReader);

    /**
     * Prints the device information.
     *
     * \n REQUIRE(this->properlyInitialized(), "The Device object must be properly initialized.");
     * \n ENSURE(true, "Device information is printed. No change in the state of the object.");
     */
    void printDeviceInfo() const;

    /**
     * Returns the device information.
     *
     * \n REQUIRE(this->properlyInitialized(), "The Device object must be properly initialized.");
     * \n ENSURE(!this->deviceName.empty(), "The device information is correctly returned.");
     */
    DeviceInfo giveDeviceInfo() const;

    /**
     * Processes a job manually and updates the processed jobs list.
     *
     * \n REQUIRE(!selectedDevice.deviceName.empty(), "The selected device must be valid.");
     * \n REQUIRE(!job.jobType.empty(), "The job must have a valid type.");
     * \n ENSURE(job.totalCost > 0, "The job total cost must be calculated and updated.");
     */
    bool manualProcess(const DeviceInfo& selectedDevice, JobInfo& job);

    /**
     * Prints the list of processed jobs.
     *
     * \n REQUIRE(true, "There are no preconditions for this function.");
     * \n ENSURE(true, "Processed jobs information is printed. No change in the state of the objects.");
     */
    bool printProcessedJobs();

    /**
     * Retrieves device information for a specific device name.
     *
     * \n REQUIRE(!deviceNameToFind.empty(), "The device name to find must not be empty.");
     * \n ENSURE(!deviceInfo.deviceName.empty(), "The device information is correctly retrieved if the device is found.");
     */
    DeviceInfo getDeviceInfo(string deviceNameToFind);

    /**
     * Writes the device information to an output file.
     *
     * \n REQUIRE(!deviceList.empty(), "The device list must not be empty.");
     * \n REQUIRE(!fileName.empty(), "The file name must not be empty.");
     * \n ENSURE(true, "Device information is written to the file. No change in the state of the objects.");
     */
    void writeDeviceInfoOutputToFile(vector<Device>& deviceList, string& fileName);

    /**
     * Prints the list of devices.
     *
     * \n REQUIRE(!devices.empty(), "The device list must not be empty.");
     * \n ENSURE(true, "Device list information is printed. No change in the state of the objects.");
     */
    void printDeviceList(vector<Device> devices);

    vector<pair<string, vector<Job>>> processedJobs;

    void setAccumulatedPages(int newAccumulatedPages) {
        accumulatedPages = newAccumulatedPages;
    }
   // It is a comment

    //vector<Job> unprocessedJobs;
    // Set log errors flag
    // Print processed jobs
    // Manually process job for selected device
    //void resetAccumulatedPages();

    // Getters
    vector<Job> getUnprocessedJobs();
    string getDeviceName() const {return deviceName;};
    int getEmissions() const {return emissions;};
    string getDeviceType() const {return deviceType;};
    int getSpeed() const {return speed;};
    int getCostPerPage() const {return cost_per_page;};
    int getAccumulatedPages() const {return accumulatedPages;};

    //Static members
    static vector<Device> devices;
    static vector<vector<pair<string, vector<Job>>>> processedJobsVector;

    // Initialization check
    //bool properlyInitialized() const { return _initCheck == this; }
};

#endif //DEVICE_H