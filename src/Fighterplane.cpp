/**
 * In deze file vindt je de 'Fighterplane' klasse.
 */

#include "Fighterplane.h"
#include<fstream>

//Default constructor will place a new plane with no name at location (0,0,0)
Fighterplane::Fighterplane() {
    this->callsign = "";
    this->pos_x = 0;
    this->pos_y = 0;
    this->pos_z = 0;
}

//constructor to set a plane on a certain location.
//ammo and healt are automaticalle initialized to 10 and 20 respectively
Fighterplane::Fighterplane(std::string callsign, int x, int y, int z) : ammo(10), health(20){
    this->callsign = callsign;
    this->pos_x = x;
    this->pos_y = y;
    this->pos_z = z;
}

std::string Fighterplane::getCallSign(){
    return callsign;
}

//Obtain positional coordinate in string format
int Fighterplane::getCoords(){
    return pos_x;
}
//Getter to obtain positional coordinate
int Fighterplane::getY(){
    return pos_y;
}
//Getter to obtain positional coordinate
int Fighterplane::getZ(){
    return pos_z;
}

//Method that allows a plane to move to a new location.
void Fighterplane::moveTo(int x, int y, int z){
    this->pos_x += x;
    this->pos_y += y;
    this->pos_z += z;
}

//Method to attack another plane.
void Fighterplane::attackPlane(Fighterplane* target){
    this->ammo -= 1;
    target->health -= 5;
}

//Prints all the information about this fighterplane to a file.
void Fighterplane::printToFile(const char * filename){
    std::ofstream outfile;
    outfile.open (filename);
    outfile << "Information about Fighterplane: \n";
    outfile << "Callsign: " + callsign + "\n";
    outfile << "Position: (" << pos_x << "," << pos_y << "," << pos_z << ")\n";
    outfile << "Health: " << health << "\n";
    outfile << "Remaining ammo: " << ammo << "\n";
    outfile.close();
}
