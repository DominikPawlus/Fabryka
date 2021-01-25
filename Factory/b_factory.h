#include <iostream>
#include <string>

#include "../Vehicles/bike.h"
#include "../Factory/factory.h"

#ifndef B_FACTORY_H
#define B_FACTORY_H

template <class Bike>
class BikeFactory : public Factory<Bike> {

public:

    explicit BikeFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency);

    void addNew(std::string color, bool basket, int gears);

    Bike * sell(const Bike &bike);
};

template <class Bike>
BikeFactory<Bike>::BikeFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency) : Factory<Bike>(brand, capacity, fuel_amount, efficiency){
}

template <class Bike>
void BikeFactory<Bike>::addNew(std::string color, bool basket, int gears) {

    std::string owner = "Fabryka";
    int capacity = 5;
    if(basket) {
        capacity += 10;
    }

    Bike bike = Bike(owner, std::move(color), this -> brand, basket, capacity, gears);
    this -> garage.push_back(bike);
}

template <class Bike>
Bike * BikeFactory<Bike>::sell(const Bike& bike) {

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

#endif //B_FACTORY_H