#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {

protected:
    std::string owner;
    std::string color;
    std::string brand;
    int capacity;

public:
    Vehicle(std::string owner, std::string color, std::string brand, int capacity);

    std::string getColor();

    int getCapacity();

    std::string getBrand();
};

#endif //VEHICLE_H