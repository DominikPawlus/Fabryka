#include "engine_vehicle.h"

Engine_Vehicle::Engine_Vehicle(std::string owner, std::string color, std::string brand, int capacity, float fuel_amount, float efficiency)
    : Vehicle(owner, color, brand, capacity), fuel_amount(fuel_amount) {
}

float Engine_Vehicle::getFuelAmount() {
    return this -> fuel_amount;
}
