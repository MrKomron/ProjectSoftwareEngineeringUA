
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Exceptions.h"

#include "Largest.h"
#include "Fighterplane.h"


#include "DesignByContract.h"


/**
 * Een voorbeeld van een functie met een contract.
 */
std::string simple_function_with_contract(int value_a, std::string value_b) {
    REQUIRE(value_a > 0, "Value a must be bigger than zero");
    REQUIRE(value_b.length() >= 4, "Value b must have more than 3 characters.");

    std::stringstream str_value;
    str_value << value_a;

    // works fine
    std::string return_value = value_b + " -> " + str_value.str();

    // if you do this, the 'ENSURE' will fail
//    std::string return_value = "";

    ENSURE(return_value != "", "Return value must never be the empty string.");

    return return_value;
}


/**
 * Eenvoudige main functie.
 */
int main(int argc, const char * argv[])
{
    std::vector<int>* listOfNumbers = new std::vector<int>();
    listOfNumbers->push_back(5);
    listOfNumbers->push_back(7);
    listOfNumbers->push_back(3);
    listOfNumbers->push_back(1);
    listOfNumbers->push_back(-1);

    std::cout << largest(listOfNumbers) << std::endl;
    std::cout << largest2(listOfNumbers) << std::endl;
    try {
        std::cout << largest2(0) << std::endl;
    } catch(std::exception * e) {
        std::cout << e->what() << std::endl;
    }
    try {
        std::cout << largest2(new std::vector<int>()) << std::endl;
    } catch(std::exception * e) {
        std::cout << e->what() << std::endl;
    }

    Fighterplane plane = Fighterplane("abc", 1,2,3);

    std::cout << "Callsign: " << plane.getCallSign() << std::endl;

    // works fine
    std::cout << simple_function_with_contract(5, "You gave the number ") << std::endl;

    // will fail
//    std::cout << simple_function_with_contract(0, "This will never print anything") << std::endl;
//    std::cout << simple_function_with_contract(5, "...") << std::endl;
}
