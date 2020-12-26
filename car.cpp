#include "car.h"

Car::Car(std::string owner, std::string color, std::string brand, int door_count, int mileage) : owner(owner), color(color), brand(brand), door_count(door_count), mileage(mileage) {
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << "Właściciel: " << car.owner << std::endl << "Kolor: " << car.color << std::endl 
    << "Marka: " << car.brand << std::endl << "Liczba drzwi: " << car.door_count << std::endl << 
    "Przebieg: " << car.mileage << std::endl;
    return out;
}

int Car::go(int km) {
    this -> mileage = mileage + km;
    return mileage;
};