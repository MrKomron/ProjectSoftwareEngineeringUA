//
// Created by Oubay on 29/02/2024.
//

#ifndef PROJECTTITLE_XMLPRINTERSYSTEMREADER_H
#define PROJECTTITLE_XMLPRINTERSYSTEMREADER_H

#include <iostream>

using namespace std;

class XMLPrinterSystemReader {
private:
    int a=1;
public:
    XMLPrinterSystemReader(const string& filepath, PrintSystem* ps) : filepath(filepath), printSystem(ps) {}
};


#endif //PROJECTTITLE_XMLPRINTERSYSTEMREADER_H
