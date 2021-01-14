#ifndef OFFICE_H
#define OFFICE_H

#include <iostream>
#include <string>
#include <fstream>
#include "../Vehicles/engine_vehicle.h"

class Office {

public:

    static void registerVehicle(Engine_Vehicle &e_vehicle, std::ifstream &plik);

};

#endif //OFFICE_H