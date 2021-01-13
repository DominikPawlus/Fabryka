#include <iostream>
#include <string>

#include "Vehicles/bike.h"

#ifndef B_FACTORY_H
#define B_FACTORY_H

class BikeFactory : public Factory {

public:

    void addNewCar(std::string color, int door_count);

    Bike * sell(const Motorcycle &motor, const std::string &motor_name);
};

#endif //B_FACTORY_H