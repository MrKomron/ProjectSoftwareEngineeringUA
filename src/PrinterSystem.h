// Created by admin on 4/28/2024.
//============================================================================
// Name        : PrinterSystem.h
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     : 1.0
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declaration of the PrinterSystem class in C++
//============================================================================

#ifndef PROJECTSOFTWAREENGINEERINGUA_PRINTERSYSTEM_H
#define PROJECTSOFTWAREENGINEERINGUA_PRINTERSYSTEM_H


class PrinterSystem {
public:
    /**
     * Starts the printer system, initializes the necessary components, and processes the XML data.
     *
     * \n ENSURE(true, "Printer system started and XML data processed.");
     */
    static void systemStart();

    /**
     * Starts the printer system in test mode.
     *
     * \n ENSURE(true, "Printer system started in test mode.");
     */
    static void systemStartTests();

    /**
     * Shuts down the printer system.
     *
     * \n ENSURE(result == 0, "Printer system successfully shut down.");
     * \return int indicating the status of the shutdown process.
     */
    static int systemOff();
};

#endif //PROJECTSOFTWAREENGINEERINGUA_PRINTERSYSTEM_H
