#include "engine_vehicle.h"

#include <utility>

Engine_Vehicle::Engine_Vehicle() {}

Engine_Vehicle::Engine_Vehicle(std::string owner, std::string color, std::string brand, int capacity, float fuel_amount, float efficiency)
    : Vehicle(std::move(owner), std::move(color), std::move(brand), capacity), fuel_amount(fuel_amount), efficiency(efficiency) {
}

bool operator==(const Engine_Vehicle& car1, const Engine_Vehicle& car2) {
    if(car1.owner == car2.owner && car1.color == car2.color && car1.brand == car2.brand) {
        return true;
    } else {
        return false;
    }
} // capacity, fuel i efficiency są zmienne - niepotrzebne do porównania

float Engine_Vehicle::getFuelAmount() const {
    return this -> fuel_amount;
}

float Engine_Vehicle::getEfficiency() const {
    return this -> efficiency;
}
