//

#include "Device.h"
#include <iostream>

using namespace std;

Device::Device(const std::string &name, int emissions, int printSpeed) {}


string Device::getName() const {
    return name;
}

int Device::getEmissions() const {
    return emissions;
}

int Device::getSpeed() const {
    return speed;
}
