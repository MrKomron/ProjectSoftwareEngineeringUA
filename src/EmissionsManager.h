//
// Created by Dell on 4/28/2024.
//

#ifndef PROJECTSOFTWAREENGINEERINGUA_EMISSIONSMANAGER_H
#define PROJECTSOFTWAREENGINEERINGUA_EMISSIONSMANAGER_H

#include <iostream>

using namespace std;

class EmissionsManager {
private:
    double totalEmissions;

public:
    EmissionsManager();
    void addEmissions(double amount);
    double getTotalEmissions() const;
};


#endif //PROJECTSOFTWAREENGINEERINGUA_EMISSIONSMANAGER_H
