#include "vehicle.h"

#include <utility>

Vehicle::Vehicle() {}

Vehicle::Vehicle(std::string owner, std::string color, std::string brand, int capacity)
    : owner(std::move(owner)), color(std::move(color)), brand(std::move(brand)),  capacity(capacity){
}

std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle) {
    out << "Właściciel: " << vehicle.owner << std::endl << "Kolor: " << vehicle.color << std::endl <<
        "Marka: " << vehicle.brand << std::endl <<
        "Przebieg: " << vehicle.mileage << std::endl << "Ładowność: " << vehicle.capacity << " kg" << std::endl;
    return out;
}

bool operator==(const Vehicle& vehicle1, const Vehicle& vehicle2) {
    if(vehicle1.owner == vehicle2.owner && vehicle1.color == vehicle2.color && vehicle1.brand == vehicle2.brand) {
        return true;
    } else {
        return false;
    }
}

std::string Vehicle::getColor() const {
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
