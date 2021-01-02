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
        Factory(std::string name = "Gigafactory");
    
        void addNewCar(std::string color, int door_count, int brand);

        Car * sell(Car car, std::string name);

        void print();

        void printNew();

        std::vector<Car> openGarage();
};

#endif //FACTORY_H