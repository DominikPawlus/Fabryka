#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "procedures.h"

#ifndef FACTORY_H
#define FACTORY_H

template <class T>
class Factory {

protected:
    std::vector<T> garage;
    std::string brand;
    int capacity;
    float fuel_amount;
    float efficiency;

public:

    Factory() = default;

    Factory(std::string  brand, int capacity, float fuel_amount, float efficiency) :
    brand(std::move(brand)), capacity(capacity), fuel_amount(fuel_amount), efficiency(efficiency){
    }

    void addNew(const std::string& color, int door_count);
    void addNew(std::string color);
    void addNew(std::string color, bool basket, int gears);

    Car * sell(const Car &car);
    Motorcycle * sell(const Motorcycle &motor);
    Bike * sell(const Bike &bike);
};

template <class T>
void Factory<T>::addNew(const std::string& color, int door_count) {

    std::string owner = "Fabryka";
    Car *car = new Car(owner, color, this -> brand, door_count, this -> capacity, this -> fuel_amount, this -> efficiency);
    this -> garage.push_back(*car);
}


template <class T>
void Factory<T>::addNew(std::string color) {

    std::string owner = "Fabryka";
    Motorcycle motor = Motorcycle(owner, std::move(color), this -> brand, this -> capacity, this -> fuel_amount, this -> efficiency);
    this -> garage.push_back(motor);

}

template <class T>
void Factory<T>::addNew(std::string color, bool basket, int gears) {

    std::string owner = "Fabryka";
    int capacity_b = 5;
    if(basket) {
        capacity_b += 10;
    }

    Bike bike = Bike(owner, std::move(color), this -> brand, basket, capacity_b, gears);
    this -> garage.push_back(bike);
}

template <class T>
Car * Factory<T>::sell(const Car &car) {

    for(int i = 0; i < this -> garage.size(); i++) {

        if(this -> garage.at(i) == car) {
            Car * tmp = new Car("Fabryka", this -> garage.at(i).getColor(), this -> garage.at(i).getBrand(), this -> garage.at(i).getDoorCount(), this -> garage.at(i).getCapacity(), this -> garage.at(i).getFuelAmount(), this -> garage.at(i).getEfficiency());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }

    vehicle_no_exist kapsula;
    throw kapsula;
}

template <class T>
Motorcycle * Factory<T>::sell(const Motorcycle& motor) {

    for(int i = 0; i < this -> garage.size(); i++) {
        if(this -> garage.at(i) == motor) {
            Motorcycle * tmp = new Motorcycle("Fabryka", this -> garage.at(i).getColor(), this -> garage.at(i).getBrand(), this -> garage.at(i).getCapacity(), this -> garage.at(i).getFuelAmount(), this -> garage.at(i).getEfficiency());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }

    vehicle_no_exist kapsula;
    throw kapsula;
}

template <class T>
Bike * Factory<T>::sell(const Bike& bike) {

    for(int i = 0; i < this -> garage.size(); i++) {
        if(this -> garage.at(i) == bike) {
            Bike * tmp = new Bike("Fabryka", this -> garage.at(i).getColor(), this -> garage.at(i).getBrand(), this -> garage.at(i).isBasket(), this -> garage.at(i).getCapacity(), this -> garage.at(i).getGears());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }

    vehicle_no_exist kapsula;
    throw kapsula;
}

#endif //FACTORY_H