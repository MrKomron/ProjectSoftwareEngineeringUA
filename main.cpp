#include "tinyxml.h"
#include <iostream>

using namespace std;

int main () {
    TiXmlDocument doc;
    if (!doc.LoadFile("eenCD.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return 1;
    }

}




