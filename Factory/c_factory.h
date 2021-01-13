#include <iostream>
#include <string>

#include "Vehicles/car.h"

#ifndef C_FACTORY_H
#define C_FACTORY_H

class CarFactory : public Factory {

public:

    void addNew(std::string color, int door_count);

    Car * sell(const &car, const std::string &car_name);

};

#endif //C_FACTORY_H