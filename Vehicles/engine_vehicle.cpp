#include "engine_vehicle.h"

#include <utility>

Engine_Vehicle::Engine_Vehicle(std::string owner, std::string color, std::string brand, int capacity, float fuel_amount, float efficiency)
    : Vehicle(std::move(owner), std::move(color), std::move(brand), capacity), fuel_amount(fuel_amount), efficiency(efficiency) {
}

std::ostream& operator<<(std::ostream& out, const Engine_Vehicle& e_vehicle) {
    out << "Właściciel: " << e_vehicle.owner << std::endl << "Kolor: " << e_vehicle.color << std::endl <<
        "Marka: " << e_vehicle.brand << std::endl <<
        "Przebieg: " << e_vehicle.mileage << std::endl << "Ładowność: " << e_vehicle.capacity << " kg" << std::endl <<
        "Ilość paliwa: " << e_vehicle.fuel_amount << " l" << std::endl << "Spalanie: " << e_vehicle.efficiency << " l/100km" << std::endl;
    return out;
}

bool operator==(const Engine_Vehicle& e_vehicle1, const Engine_Vehicle& e_vehicle2) { //operator porównania jest przeładowany dla każdej klasy w razie dodania nowych pól
    if(e_vehicle1.owner == e_vehicle2.owner && e_vehicle1.color == e_vehicle2.color && e_vehicle1.brand == e_vehicle2.brand) {
        return true;
    } else {
        return false;
    }
} // capacity, fuel i efficiency są zmienne - niepotrzebne do porównania

void Engine_Vehicle::go(float km) {

    if(!this -> license_plate) {
        std::cout << "Żeby móc jeździć pojazdem, musisz go najpierw zarejestrować!" << std::endl;
    }
    this -> mileage += km;
    this -> fuel_amount -= km / 100 * this -> getEfficiency();
    std::cout << "Przejechałeś " << km << " kilometrów pojazdem o rejestracji: " << std::endl << this -> number << std::endl;
}

float Engine_Vehicle::getFuelAmount() const {
    return this -> fuel_amount;
}

float Engine_Vehicle::getEfficiency() const {
    return this -> efficiency;
}
