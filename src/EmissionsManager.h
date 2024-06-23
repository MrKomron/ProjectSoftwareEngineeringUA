// Created by Dell on 4/29/2024.

//============================================================================
// Name        : EmissionsManager.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Description : Declaration of the EmissionsManager class in C++
//============================================================================

#ifndef PROJECTSOFTWAREENGINEERINGUA_EMISSIONSMANAGER_H
#define PROJECTSOFTWAREENGINEERINGUA_EMISSIONSMANAGER_H

#include "DesignByContract.h"

class EmissionsManager {
private:
    int emissionsResult;

public:
    /**
     * Constructor that initializes the EmissionsManager object.
     *
     * \n ENSURE(emissionsResult == 0, "Emissions result must be initialized to 0.");
     */
    EmissionsManager();

    /**
     * Adds the specified amount to the total emissions.
     *
     * \n REQUIRE(amount > 0, "The amount to add must be positive.");
     * \n ENSURE(emissionsResult >= amount, "The emissions result must be correctly updated.");
     */
    void addEmissions(int amount);

    /**
     * Returns the total emissions result.
     *
     * \n ENSURE(result >= 0, "The emissions result must be non-negative.");
     * \return The total emissions result.
     */
    int getEmissionsResult() const;
};

#endif //PROJECTSOFTWAREENGINEERINGUA_EMISSIONSMANAGER_H
