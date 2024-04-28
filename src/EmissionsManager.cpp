//
// Created by Dell on 4/28/2024.
//

#include "EmissionsManager.h"

EmissionsManager::EmissionsManager() : totalEmissions(0) {}

void EmissionsManager::addEmissions(double amount) {
    totalEmissions += amount;
    std::cout << "Added " << amount << " CO2 emissions to the total, new total is " << totalEmissions << std::endl;
}

double EmissionsManager::getTotalEmissions() const {
    return totalEmissions;
}
