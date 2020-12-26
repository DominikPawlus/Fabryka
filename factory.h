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

        void sell(Car car);

        void print();
};

#endif //FACTORY_H