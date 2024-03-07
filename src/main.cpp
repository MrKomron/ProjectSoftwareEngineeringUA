
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Exceptions.h"
#include "XMLPrinterSystemReader.h"



/**
 * Een voorbeeld van een functie met een contract.
 */
//std::string simple_function_with_contract(int value_a, std::string value_b) {
//    REQUIRE(value_a > 0, "Value a must be bigger than zero");
//    REQUIRE(value_b.length() >= 4, "Value b must have more than 3 characters.");
//
//    std::stringstream str_value;
//    str_value << value_a;
//
//    // works fine
//    std::string return_value = value_b + " -> " + str_value.str();
//
//    // if you do this, the 'ENSURE' will fail
////    std::string return_value = "";
//
//    ENSURE(return_value != "", "Return value must never be the empty string.");
//
//    return return_value;
//}


/**
 * Eenvoudige main functie.
 */

/*
int main(int argc, const char * argv[])
{
    std::vector<int>* listOfNumbers = new std::vector<int>();
    listOfNumbers->push_back(5);
    listOfNumbers->push_back(7);
    listOfNumbers->push_back(3);
    listOfNumbers->push_back(1);
    listOfNumbers->push_back(-1);
}
*/

/*
int main() {
    XMLPrinterSystemReader reader;
    try {
        reader.parseFile("path/to/your/xmlfile.xml");
    } catch (const std::exception& e) {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }
    // Further processing or user interaction
    return 0;
}
*/