#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {

protected:

    std::string brand;
    int capacity;
    int mileage = 0;

public:

    std::string color;
    std::string owner;

    Vehicle();
    Vehicle(std::string owner, std::string color, std::string brand, int capacity);

    std::string getColor();

    std::string getBrand();

    int getCapacity() const;

    int getMileage() const;
};

#endif //VEHICLE_H