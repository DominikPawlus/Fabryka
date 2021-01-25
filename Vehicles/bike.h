#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string>
#include <vector>
#include "vehicle.h"

class Bike : public Vehicle {
    private:

        bool basket;
        int gears = 8;

    public:

        Bike() = default;

        Bike(std::string owner, std::string color, std::string brand, bool basket, int capacity, int gears);

        void go(float km);

        bool isBasket() const;
        int getGears() const;
};

#endif //BIKE_H