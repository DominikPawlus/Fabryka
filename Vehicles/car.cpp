#include "car.h"

Car::Car(std::string owner, std::string color, std::string brand, int door_count, int capacity, float fuel_amount, float efficiency)
    : Engine_Vehicle(owner, color, brand, capacity, fuel_amount, efficiency), door_count(door_count) {
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << "Właściciel: " << car.owner << std::endl << "Kolor: " << car.color << std::endl <<
    "Marka: " << car.brand << std::endl << "Liczba drzwi: " << car.door_count << std::endl <<
    "Przebieg: " << car.mileage << std::endl << "Ładowność: " << car.capacity << std::endl <<
    "Ilość paliwa: " << car.fuel_amount << std::endl;
    return out;
}

bool operator==(const Car& car1, const Car& car2) {
    if(car1.owner == car2.owner && car1.color == car2.color && car1.brand == car2.brand && car1.door_count == car2.door_count) {
        return true; 
    } else {
        return false;
    }
} // capacity i fuel są zmienne - niepotrzebne do porównania

int Car::go(float km, std::vector<Car> &garage) {
    for(int i = 0; i < garage.size(); i++) {
        if(garage.at(i) == *this) {
            garage.at(i).mileage += km;
            garage.at(i).fuel_amount -= km/10;
            std::cout << garage.at(i) << std::endl;
            return garage.at(i).mileage;
        }
    }
    return 0;
};

int Car::getDoorCount(){
    return this->door_count;
};