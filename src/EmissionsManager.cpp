// Created by Dell on 4/29/2024.

//============================================================================
// Name        : EmissionsManager.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Description : Implementation of the EmissionsManager class in C++
//============================================================================
//
#include "EmissionsManager.h"
#include <iostream>

using namespace std;

EmissionsManager::EmissionsManager() : emissionsResult(0) {
    ENSURE(emissionsResult == 0, "Emissions result must be initialized to 0.");
}

void EmissionsManager::addEmissions(int amount) {
    REQUIRE(amount > 0, "The amount to add must be positive.");
    emissionsResult += amount;
    cout << "Added " << amount << " CO2 emissions to the total, new total is " << emissionsResult << endl;
    ENSURE(emissionsResult >= amount, "The emissions result must be correctly updated.");
}

int EmissionsManager::getEmissionsResult() const {
    ENSURE(emissionsResult >= 0, "The emissions result must be non-negative.");
    return emissionsResult;
}
