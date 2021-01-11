#include <iostream>
#include <string>
#include <vector>

#include "Vehicles/car.h"

#ifndef FACTORY_H
#define FACTORY_H

class Factory{
    private:
        std::string name;
        std::vector<Car> garage;

    public:
        explicit Factory(std::string name = "Gigafactory");
    
        void addNewCar(std::string color, int door_count, int brand);

        Car * sell(const Car& car, const std::string& car_name);

        void printNew();
};

#endif //FACTORY_H