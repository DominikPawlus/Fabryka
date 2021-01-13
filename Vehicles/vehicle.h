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

    friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle);
    friend bool operator==(const Vehicle& vehicle1, const Vehicle& vehicle2);

    std::string getColor() const;

    std::string getBrand();

    int getCapacity() const;

    int getMileage() const;
};

#endif //VEHICLE_H