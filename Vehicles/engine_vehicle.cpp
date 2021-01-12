#include "engine_vehicle.h"

#include <utility>

Engine_Vehicle::Engine_Vehicle() = default;

Engine_Vehicle::Engine_Vehicle(std::string owner, std::string color, std::string brand, int capacity, float fuel_amount, float efficiency)
    : Vehicle(std::move(owner), std::move(color), std::move(brand), capacity), fuel_amount(fuel_amount), efficiency(efficiency) {
}

std::ostream& operator<<(std::ostream& out, const Engine_Vehicle& car) {
    out << "Właściciel: " << car.owner << std::endl << "Kolor: " << car.color << std::endl <<
        "Marka: " << car.brand << std::endl <<
        "Przebieg: " << car.mileage << std::endl << "Ładowność: " << car.capacity << " kg" << std::endl <<
        "Ilość paliwa: " << car.fuel_amount << " l" << std::endl << "Spalanie: " << car.efficiency << " l/100km" << std::endl;
    return out;
}

bool operator==(const Engine_Vehicle& car1, const Engine_Vehicle& car2) {
    if(car1.owner == car2.owner && car1.color == car2.color && car1.brand == car2.brand) {
        return true;
    } else {
        return false;
    }
} // capacity, fuel i efficiency są zmienne - niepotrzebne do porównania

int Engine_Vehicle::go(float km, std::vector<Engine_Vehicle> &garage) {
    for(int i = 0; i < garage.size(); i++) {
        if(garage.at(i) == *this) {
            garage.at(i).mileage += km;
            garage.at(i).fuel_amount -= km / 100 * garage.at(i).getEfficiency();
            std::cout << "Przejechałeś " << km << " kilometrów samochodem: " << std::endl << garage.at(i) << std::endl;
            return garage.at(i).mileage;
        }
    }
    return 0;
};

float Engine_Vehicle::getFuelAmount() const {
    return this -> fuel_amount;
}

float Engine_Vehicle::getEfficiency() const {
    return this -> efficiency;
}

void Engine_Vehicle::splitMileage() {
    this -> mileage /= 2;
}
