#include <iostream>
#include <string>

#include "Vehicles/motorcycle.h"

#ifndef M_FACTORY_H
#define M_FACTORY_H

class MotorFactory : public Factory {

public:

    void addNew(std::string color, int door_count);

    Motorcycle * sell(const Motorcycle &motor, const std::string &motor_name);
};

#endif //M_FACTORY_H