#include "tinyxml.h"
#include <iostream>

using namespace std;

int main () {
    TiXmlDocument doc;
    if(!doc.LoadFile("eenCD.xml")) {
        cerr << doc.ErrorDesc() << endl;
        return 1;
    }

}




