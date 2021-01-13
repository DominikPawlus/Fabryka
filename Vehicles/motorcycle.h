#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H(args)

#include <iostream>
#include <string>
#include <vector>
#include "engine_vehicle.h"

class Motorcycle : public Engine_Vehicle {

public:

    Motorcycle(std::string owner, std::string color, std::string brand, int capacity, float fuel_amount, float efficiency);

    friend std::ostream& operator<<(std::ostream& out, const Motorcycle& motor);
    friend bool operator==(const Motorcycle& motor1, const Motorcycle& motor2);

};

#endif //MOTORCYCLE_H