#include "vehicle.h"

#include <utility>

Vehicle::Vehicle() {}

Vehicle::Vehicle(std::string owner, std::string color, std::string brand, int capacity)
    : owner(std::move(owner)), color(std::move(color)), brand(std::move(brand)),  capacity(capacity){
}

std::string Vehicle::getColor() {
    return this->color;
};

int Vehicle::getCapacity() const {
    return this -> capacity;
}

std::string Vehicle::getBrand() {
    return this -> brand;
}

int Vehicle::getMileage() const {
    return this -> mileage;
}
