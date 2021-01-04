#ifndef VARNISHER_H
#define VARNISHER_H

#include <iostream>
#include <string>
#include <fstream>
#include "Vehicles/vehicle.h"

class Varnisher {

public:

    static void changeColor(Vehicle &vehicle, std::ifstream &plik);
};

#endif //VARNISHER_H