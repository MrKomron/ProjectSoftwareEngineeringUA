//
// Created by Oubay on 29/02/2024.
//

#ifndef PROJECTTITLE_DEVICE_H
#define PROJECTTITLE_DEVICE_H

#include <string>

using namespace std;

class Device {
private:
    string name;   // de naam van de printer
    int emissions; // CO2-uitstoot
    int speed;     // print snelheid
    //int workload; //

public:
    // de constructor initialiseert een printer met een naam, CO2-uitstoot en print snelheid
    Device(const string& name, int emissions, int printSpeed);
    // getters
    string getName() const;
    int getEmissions() const;
    int getSpeed() const;
};





// Trashcan:
/*

 : name(name), emissions(emissions), speed(printSpeed) {}


 {return name; }
 {return emissions; }
 { return speed; }

 */

#endif //PROJECTTITLE_DEVICE_H
