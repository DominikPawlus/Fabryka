#include "car.h"

Car::Car(std::string owner, std::string color, std::string brand, int door_count, int mileage) : owner(owner), color(color), brand(brand), door_count(door_count), mileage(mileage) {
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << "Właściciel: " << car.owner << std::endl << "Kolor: " << car.color << std::endl 
    << "Marka: " << car.brand << std::endl << "Liczba drzwi: " << car.door_count << std::endl << 
    "Przebieg: " << car.mileage << std::endl;
    return out;
}

bool operator==(const Car& car1, const Car& car2) {
    if(car1.owner == car2.owner && car1.color == car2.color && car1.brand == car2.brand && car1.door_count == car2.door_count) {
        return true; 
    } else {
        return false;
    }
}

int Car::go(int km) {
    mileage = this -> mileage + km;
    return mileage;
};

std::string Car::getColor(){
    return this->color;
};

int Car::getDoorCount(){
    return this->door_count;
};