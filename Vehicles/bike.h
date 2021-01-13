#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string>
#include "vehicle.h"

class Bike : public Vehicle {
    private:
        bool basket;

    public:

        Bike(std::string owner, std::string color, std::string brand, bool basket, int capacity);

        bool isBasket();
};

#endif //BIKE_H