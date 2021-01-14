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

    bool license_plate;
    std::string number = "NIEZAREJESTROWANY";

    Engine_Vehicle();

    Engine_Vehicle(std::string owner, std::string color, std::string brand, int capacity, float fuel_amount,
                   float efficiency);

    friend std::ostream &operator<<(std::ostream &out, const Engine_Vehicle &e_vehicle);
    friend bool operator==(const Engine_Vehicle &e_vehicle1, const Engine_Vehicle &e_vehicle2);

    float go(float km);

    float getFuelAmount() const;
    float getEfficiency() const;
    bool isRegistered();
};

#endif //ENGINE_VEHICLE_H