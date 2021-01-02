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

        int getCapacity() {
            if(this -> basket) {
                this -> capacity += 10;
            }
            return this -> capacity;
        }
};

#endif //BIKE_H