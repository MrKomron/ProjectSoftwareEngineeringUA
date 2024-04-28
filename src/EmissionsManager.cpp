//
// Created by Dell on 4/29/2024.
//

#include "EmissionsManager.h"
#include <iostream>

using namespace std;

EmissionsManager::EmissionsManager() : emissionsResult(0) {}

void EmissionsManager::addEmissions(double amount) {
    emissionsResult += amount;
    cout << "Added " << amount << " CO2 emissions to the total, new total is " << emissionsResult << endl;
}

double EmissionsManager::getEmissionsResult() const {
    return emissionsResult;
}
