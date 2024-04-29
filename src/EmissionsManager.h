//
// Created by Dell on 4/29/2024.
//

#ifndef PROJECTSOFTWAREENGINEERINGUA_EMISSIONSMANAGER_H
#define PROJECTSOFTWAREENGINEERINGUA_EMISSIONSMANAGER_H


class EmissionsManager {
private:
    int emissionsResult;
public:
    EmissionsManager();
    void addEmissions(int amount);
    int getEmissionsResult() const;
};


#endif //PROJECTSOFTWAREENGINEERINGUA_EMISSIONSMANAGER_H
