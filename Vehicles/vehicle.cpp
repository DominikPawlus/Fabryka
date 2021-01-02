#include "vehicle.h"

Vehicle::Vehicle(std::string owner, std::string color, std::string brand, int capacity)
    : owner(owner), color(color), brand(brand),  capacity(capacity){
}

std::string Vehicle::getColor() {
    return this->color;
};

int Vehicle::getCapacity() {
    return this -> capacity;
}

std::string Vehicle::getBrand() {
    return this -> brand;
}