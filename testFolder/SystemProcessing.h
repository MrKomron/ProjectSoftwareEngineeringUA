//
// Created by admin on 3/13/2024.
//
#ifndef TESTFOLDER_SYSTEMPROCESSING_H
#define TESTFOLDER_SYSTEMPROCESSING_H
#include <iostream>
#include <string>
#include <vector>
#include "XMLREADER/XMLReader.h"
#include "Device.h"
#include "Job.h"

class System{
public:
    static int manualProcess(std::vector<Device>& devices, std::vector<Job>& jobs);
    static int automatedProcess(std::vector<Device>& devices, std::vector<Job>& jobs);

};

#endif //TESTFOLDER_SYSTEMPROCESSING_H
