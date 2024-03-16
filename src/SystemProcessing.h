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
 * @brief Voert handmatige verwerking uit op een verzameling van apparaten en taken.
 *
 * @param devices Een referentie naar een vector van `Device` objecten die de apparaten vertegenwoordigt.
 * @param jobs Een referentie naar een vector van `Job` objecten die de taken vertegenwoordigt.
 *
 * @return Een integer waarde die het resultaat van de verwerking aangeeft.
 *
 * @pre De vector `devices` moet geïnitialiseerd zijn en mag niet leeg zijn, omdat er operaties op de apparaten worden uitgevoerd.
 *      De vector `jobs` moet geïnitialiseerd zijn. Afhankelijk van de implementatie, kan deze leeg zijn of moet er ten minste één `Job` object in de vector zijn.
 *
 * @post De staat van sommige of alle `Device` objecten in de `devices` vector kan gewijzigd zijn als resultaat van de uitgevoerde taken.
 *       De `jobs` vector kan worden gemodificeerd, taken kunnen worden gemarkeerd als voltooid of verwijderd, afhankelijk van de logica van de verwerking.
 *       De functie retourneert een integer die aangeeft of de verwerking succesvol was (bijvoorbeeld `0` voor succes, andere waarden kunnen duiden op verschillende fouten of resultaten).
 */
    bool manualProcess(std::vector<Device>& devices, std::vector<Job>& jobs);
//    static int automatedProcess(std::vector<Device>& devices, std::vector<Job>& jobs);
    bool automatedProcess(std::vector<Device>& devices, std::vector<Job>& jobs);

    void setlogerrors(bool log) { logerrors = log; }

};

#endif //TESTFOLDER_SYSTEMPROCESSING_H
