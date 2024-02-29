/**
 * In deze file vindt je de 'Fighterplane' klasse.
 */

#ifndef FIGHTERPLANE_H
#define FIGHTERPLANE_H

#include <string>

class Fighterplane {
private:
    std::string callsign;
    int pos_x; //positional coordinate
    int pos_y; //positional coordinate
    int pos_z; //positional coordinate
    int ammo; //keeps track of the number of missiles
    int health; //the remaining hitpoints the plane still has. When this reaches 0 the plane is dead!
public:
    //Default constructor will place a new plane with no name at location (0,0,0)
    Fighterplane();
    
    //constructor to set a plane on a certain location.
    //ammo and healt are automaticalle initialized to 10 and 20 respectively
    Fighterplane(std::string callsign, int x, int y, int z);
    
    std::string getCallSign();
    
    //Obtain positional coordinate in string format
    int getCoords();

    //Getter to obtain positional coordinate
    int getY();

    //Getter to obtain positional coordinate
    int getZ();
    
    //Method that allows a plane to move to a new location.
    void moveTo(int x, int y, int z);
    
    //Method to attack another plane.
    void attackPlane(Fighterplane* target);
    
    //Prints all the information about this fighterplane to a file.
    void printToFile(const char * filename);
};

#endif
