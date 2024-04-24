//============================================================================
// Name        : SystemProcessing.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================

#ifndef TESTFOLDER_SYSTEMPROCESSING_H
#define TESTFOLDER_SYSTEMPROCESSING_H
#include <iostream>
#include <string>
#include <vector>
#include "XMLREADER/XMLReader.h"
#include "Device.h"
#include "Job.h"

class System{
private:
    bool logerrors = false;
public:
    /**
   * Voert handmatige verwerking uit op een verzameling van apparaten en taken.
   *
   * REQUIRE(!devices.empty() && devicesInitialized(devices), "De vector 'devices' moet geïnitialiseerd zijn en mag niet leeg zijn, omdat er operaties op de apparaten worden uitgevoerd.");
   * REQUIRE(jobsInitialized(jobs), "De vector 'jobs' moet geïnitialiseerd zijn. Afhankelijk van de implementatie, kan deze leeg zijn of moet er ten minste één 'Job' object in de vector zijn.");
   * ENSURE(devicesModified(devices) || jobsModified(jobs), "De staat van sommige of alle 'Device' objecten in de 'devices' vector kan gewijzigd zijn als resultaat van de uitgevoerde taken. De 'jobs' vector kan worden gemodificeerd, taken kunnen worden gemarkeerd als voltooid of verwijderd.");
   * ENSURE(processResult() == 0, "De functie retourneert een integer die aangeeft of de verwerking succesvol was (bijvoorbeeld '0' voor succes, andere waarden kunnen duiden op verschillende fouten of resultaten).");
   */

    bool manualProcess(std::vector<Device>& devices, std::vector<Job>& jobs);
//    static int automatedProcess(std::vector<Device>& devices, std::vector<Job>& jobs);
    bool automatedProcess(std::vector<Device>& devices, std::vector<Job>& jobs);

    void setlogerrors(bool log) { logerrors = log; }

};

#endif //TESTFOLDER_SYSTEMPROCESSING_H
