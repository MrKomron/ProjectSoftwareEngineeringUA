//============================================================================
// Name        : XMLReader.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================

#include "XMLReader.h"
#include "tinyxml.h"
#include <iostream>
#include "../DesignByContract.h"

using namespace std;

XMLReader::XMLReader() {
    // Empty Constructor used in main.cpp to initialize the first reading/parsing of the XML file.
    _initCheck = this; // Mark the object as initialized
    ENSURE(properlyInitialized(), "Constructor must end in properlyInitialized state");
}

// A Boolean type function to return whether the parsing or reading of the file is successful or not.
bool XMLReader::readerXML(string filename) {
    REQUIRE(!filename.empty(), "Filename must not be empty");
    REQUIRE(properlyInitialized(), "XMLReader wasn't properly initialized when calling readerXML");
    // Creates an instance of TiXmlDocument class named "doc"

    // Loads the file to start the parsing.
    if (!doc.LoadFile(filename.c_str())) {
        cerr << "Failed to load file: " << doc.ErrorDesc() << endl;
        // Returns a false if unable to open the file. (This then would be used to exit the program in main.cpp)

        // ENSURE(false, "readerXML must return false if file loading fails");
        // ^^ No need to ENSURE(false) here, as we are returning false
        return false; // Directly return false on failure without ENSURE
    }

    // Checks the root of the XML file if it is "SYSTEM"
    TiXmlElement* root = doc.FirstChildElement("SYSTEM");
    if (!root) {
        cerr << "Failed to find root element SYSTEM." << endl;
        ENSURE(false, "readerXML must return false if root element is missing");
    }

    // Sets a variable to be used later for the checking of the availability of any printing device in the system.
    bool foundDevice = false;
    // Loop through DEVICE elements
    // If one element is missing it will raise error flag and would continue with the parsing.
    for (TiXmlElement* deviceElement = root->FirstChildElement("DEVICE"); deviceElement; deviceElement = deviceElement->NextSiblingElement("DEVICE")) {
        // Create a new vector instance for every device found.
        DeviceInfo deviceInfo;

        bool validDevice = true; // Flag to track if the device is valid
        // Handles if the element is missing then would skip everything and would just go to the next device.
        // Get name element from DEVICE.
        TiXmlElement* nameElement = deviceElement->FirstChildElement("name");
        if (!nameElement) {
            cerr << "Failed to find NAME element for the device. Continuing onto the next attribute." << endl;
            validDevice = false;
        } else {
            const char* deviceNameText = nameElement->GetText(); // Make a constant variable for the name of the device.
            if (!deviceNameText) {
                cerr << "Device name is empty for the device. Continuing onto the next attribute." << endl;
                validDevice = false;
            } else {
                deviceInfo.deviceName = deviceNameText;
            }
        }
        // Get emissions element from DEVICE.
        TiXmlElement* emissionsElement = deviceElement->FirstChildElement("emissions");
        if (!emissionsElement) {
            cerr << "Failed to find EMISSIONS element for the device. Continuing onto the next attribute." << endl;
            validDevice = false;
        } else {
            const char* emissionsText = emissionsElement->GetText(); // Make a constant variable for the emissions of the device.
            if (!emissionsText) {
                cerr << "Emissions value is missing or empty for the device. Continuing onto the next attribute." << endl;
                validDevice = false;
            } else {
                int emissionValue = atoi(emissionsText); // Convert the text into integer.
                if (emissionValue <=0){
                    cerr << "Invalid emission value for the device. Continuing onto the next attribute." << endl;
                } else {
                    deviceInfo.emissions = emissionValue;
                }

            }
        }
        // Get type element from DEVICE.
        TiXmlElement* typeElement = deviceElement->FirstChildElement("type");
        if (!typeElement) {
            cerr << "Failed to find TYPE element for the device. Continuing onto the next attribute." << endl;
            validDevice = false;
        } else {
            const char* typeText = typeElement->GetText(); // Make a constant variable for the name of the device.
            if (!typeText) {
                cerr << "Device type is empty for the device. Continuing onto the next attribute." << endl;
                validDevice = false;
            } else {
                try {
                    deviceInfo.deviceType = stoi(typeText);
                    cerr << "Type is an integer and is invalid for a device type. Continuing onto the next attribute." << endl;
                    validDevice = false;
                } catch (const invalid_argument& e) {
                    deviceInfo.deviceType = typeText;
                }
            }
        }
        // Get speed element from DEVICE.
        TiXmlElement* speedElement = deviceElement->FirstChildElement("speed");
        if (!speedElement) {
            cerr << "Failed to find SPEED element for the device. Continuing onto the next attribute." << endl;
            validDevice = false;
        } else {
            const char* speedText = speedElement->GetText(); // Make a constant variable for the speed of the device.
            if (!speedText) {
                cerr << "Speed value is missing or empty for the device. Continuing onto the next attribute." << endl;
                validDevice = false;
            } else {
                int speedValue = atoi(speedText); // Convert the text into integer.
                if (speedValue <=0) {
                    cerr << "Invalid speed value for the device. Continuing onto the next attribute." << endl;
                } else {
                    deviceInfo.speed = speedValue;
                }
            }
        }
        // Get cost element from DEVICE.
        TiXmlElement* costppElement = deviceElement->FirstChildElement("cost");
        if (!costppElement) {
            cerr << "Failed to find COST element for the device. Continuing onto the next attribute." << endl;
            validDevice = false;
        } else {
            const char* costppText = costppElement->GetText(); // Make a constant variable for the speed of the device.
            if (!costppText) {
                cerr << "Cost value is missing or empty for the device. Continuing onto the next attribute." << endl;
                validDevice = false;
            } else {
                int costppValue = atoi(costppText); // Convert the text into integer.
                if (costppValue <=0) {
                    cerr << "Invalid cost value for the device. Continuing onto the next attribute." << endl;
                } else {
                    deviceInfo.costpp = costppValue;
                }
            }
        }

        if (!validDevice) cerr << "Device not valid! Some elements may be missing."<< endl;
        // If the device is valid, add it to the list
        if (validDevice) {
            // Sets the data in the list of devices.
            deviceInfoList.push_back(deviceInfo);
            // Initialize the value to true.
            foundDevice = true;
        }
    }
    // Checks the value of the foundDevice.
    if (!foundDevice) {
        cerr << "There is no device in the system." << endl;
    }

    // Loop through JOB elements.
    // If one element is missing it will skip the other elements and will just process the next job.
    for (TiXmlElement* jobElement = root->FirstChildElement("JOB"); jobElement; jobElement = jobElement->NextSiblingElement("JOB")) {
        // Create a new Job object for each JOB element.
        JobInfo jobInfo;

        bool validJob = true;
        // Get jobNumber element from JOB.
        TiXmlElement *jobNumberElement = jobElement->FirstChildElement("jobNumber");
        if (!jobNumberElement) {
            cerr << "Failed to find jobNumber element for a job. Continuing onto the next attribute." << endl;
            validJob = false;
        } else {
            const char *jobNumberText = jobNumberElement->GetText();
            if (!jobNumberText) {
                cerr << "Job number is empty for the job. Continuing onto the next attribute." << endl;
                validJob = false;
            } else {
                int jobNumberValue = atoi(jobNumberElement->GetText());
                if (jobNumberValue <=0) {
                    cerr << "Invalid job number value for the job. Continuing onto the next attribute." << endl;
                } else {
                    jobInfo.jobNumber = jobNumberValue;
                }
            }
        }
        // Get pageCount element from JOB.
        TiXmlElement *pageCountElement = jobElement->FirstChildElement("pageCount");
        if (!pageCountElement) {
            cerr << "Failed to find pageCount element for a job. Continuing onto the next attribute." << endl;
            validJob = false;
        } else {
            const char *pageCountText = pageCountElement->GetText();
            if (!pageCountText) {
                cerr << "Page count is missing or empty for the job. Continuing onto the next attribute."<< endl;
                validJob = false;
            } else {
                int pageCountValue = atoi(pageCountElement->GetText());
                if (pageCountValue <= 0) {
                    cerr << "Invalid page count value for the job. Continuing onto the next attribute." << endl;
                } else {
                    jobInfo.pageCount = pageCountValue;
                }
            }
        }

        // Get userName element from JOB.
        TiXmlElement *typeElement = jobElement->FirstChildElement("type");
        if (!typeElement) {
            cerr << "Failed to find type element for a job. Continuing onto the next attribute." << endl;
            validJob = false;
        } else {
            const char *typeText = typeElement->GetText();
            if (!typeText) {
                cerr << "Type is missing or empty for a job. Continuing onto the next attribute." << endl;
                validJob = false;
            } else {
                try {
                    jobInfo.jobType = stoi(typeText);
                    cerr << "Type is an integer and is invalid for a job type. Continuing onto the next attribute." << endl;
                    validJob = false;
                } catch (const invalid_argument& e) {
                    jobInfo.jobType = typeText;
                }
            }
        }

        // Get userName element from JOB.
        TiXmlElement *userNameElement = jobElement->FirstChildElement("userName");
        if (!userNameElement) {
            cerr << "Failed to find userName element for a job. Continuing onto the next attribute." << endl;
            validJob = false;
        } else {
            const char *userNameText = userNameElement->GetText();
            if (!userNameText) {
                cerr << "Username is missing or empty for a job. Continuing onto the next attribute." << endl;
                validJob = false;
            } else {
                jobInfo.userName = userNameElement->GetText();
            }
        }
        if (validJob) {
            jobInfo.totalCost = 0;
            // Sets the data in the list of devices.
            jobInfoList.push_back(jobInfo);
        } else {
            cerr<< "Invalid Job! Some elements may be missing." << endl;
        }
    }
    doc.Clear();
    ENSURE(true, "readerXML must return true if parsing is successful");
    return true; // Return true indicating successful XML reading
}