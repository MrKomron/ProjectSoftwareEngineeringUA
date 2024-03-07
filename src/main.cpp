#include "tinyxml.h"
#include <iostream>
#include <string>


using namespace std;

int main() {
    TiXmlDocument doc;
    if (!doc.LoadFile("C:\\Users\\Dell\\Desktop\\university 2023-2024\\semester 2\\week2\\src\\data.xml")) {
        cerr << "Failed to load file: " << doc.ErrorDesc() << endl;
        return 1;
    }

    TiXmlElement* root = doc.FirstChildElement("SYSTEM");
    if (!root) {
        cerr << "Failed to find root element SYSTEM." << endl;
        return 1;
    }

    // Get DEVICE element
    TiXmlElement* deviceElement = root->FirstChildElement("DEVICE");
    if (!deviceElement) {
        cerr << "Failed to find DEVICE element." << endl;
        return 1;
    }

    // Get name element from DEVICE
    TiXmlElement* nameElement = deviceElement->FirstChildElement("name");
    if (!nameElement) {
        cerr << "Failed to find NAME element." << endl;
        return 1;
    }

    // Get name element from DEVICE
    TiXmlElement* emissionsElement = deviceElement->FirstChildElement("emissions");
    if (!emissionsElement) {
        cerr << "Failed to find EMISSIONS element." << endl;
        return 1;
    }

    // Get name element from DEVICE
    TiXmlElement* speedElement = deviceElement->FirstChildElement("speed");
    if (!speedElement) {
        cerr << "Failed to find SPEED element." << endl;
        return 1;
    }

    string device = nameElement->GetText(); // Get name text from nameElement
    string emissions = emissionsElement->GetText();
    string speed = speedElement->GetText();

    if (device.empty()) {
        cerr << "Device name is empty." << endl;
        return 1;
    }

    cout << "DEVICE: " << device << endl;
    cout << "Emissions: " << emissions << endl;
    cout << "Speed: " << speed << endl;

    // Loop through JOB elements
    for (TiXmlElement* jobElement = root->FirstChildElement("JOB"); jobElement; jobElement = jobElement->NextSiblingElement("JOB")) {
        // Get jobNumber, pageCount, and userName elements from JOB
        TiXmlElement* jobNumberElement = jobElement->FirstChildElement("jobNumber");
        TiXmlElement* pageCountElement = jobElement->FirstChildElement("pageCount");
        TiXmlElement* userNameElement = jobElement->FirstChildElement("userName");

        if (jobNumberElement && pageCountElement && userNameElement) {
            string jobNumber = jobNumberElement->GetText();
            string pageCount = pageCountElement->GetText();
            string userName = userNameElement->GetText();

            cout << "JOB Number: " << jobNumber << endl;
            cout << "Page Count: " << pageCount << endl;
            cout << "User Name: " << userName << endl;
        } else {
            cerr << "Missing elements in JOB." << endl;
        }
    }

    return 0;
}
