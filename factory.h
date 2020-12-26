#include <iostream>
#include <string>
#include <vector>

#include "car.h"

#ifndef FACTORY_H
#define FACTORY_H

class Factory{
    private:
        std::string name;
        std::vector<Car> garage;

    public:
        Factory(std::string name = "Factory");
    
        void addNewCar(std::string color, int door_count);

        Car * sell(Car car, std::string name);

        void print();

        void printNew();
};

#endif //FACTORY_H