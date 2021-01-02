#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H(args)

#include <iostream>
#include <string>
#include "engine_vehicle.h"

class Motorcycle : public Engine_Vehicle {
public:
    Motorcycle(std::string owner, std::string color, std::string brand, int capacity, float fuel_amount, float efficiency);
};

#endif //MOTORCYCLE_H