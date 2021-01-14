#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string>
#include <vector>
#include "vehicle.h"

class Bike : public Vehicle {
    private:

        bool basket;
        int gears;

    public:

        Bike(std::string owner, std::string color, std::string brand, bool basket, int capacity);

        float go(float km);

        bool isBasket();
};

#endif //BIKE_H