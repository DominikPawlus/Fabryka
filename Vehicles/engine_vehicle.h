#ifndef ENGINE_VEHICLE_H
#define ENGINE_VEHICLE_H

#include <iostream>
#include <string>
#include "vehicle.h"

class Engine_Vehicle : public Vehicle {

protected:
    float fuel_amount;
    float efficiency;

public:
    Engine_Vehicle(std::string owner, std::string color, std::string brand, int capacity, float fuel_amount, float efficiency);

    float getFuelAmount();
};

#endif //ENGINE_VEHICLE_H