#ifndef ENGINE_VEHICLE_H
#define ENGINE_VEHICLE_H

#include <iostream>
#include <string>
#include <vector>
#include "vehicle.h"

class Engine_Vehicle : public Vehicle {

protected:
    float fuel_amount;
    float efficiency;

public:

    Engine_Vehicle();
    Engine_Vehicle(std::string owner, std::string color, std::string brand, int capacity, float fuel_amount, float efficiency);

    friend std::ostream& operator<<(std::ostream& out, const Engine_Vehicle& car);

    friend bool operator==(const Engine_Vehicle& car1, const Engine_Vehicle& car2);

    int go(float km, std::vector<Engine_Vehicle> &garage);

    float getFuelAmount() const;

    float getEfficiency() const;

    void splitMileage();
};

#endif //ENGINE_VEHICLE_H