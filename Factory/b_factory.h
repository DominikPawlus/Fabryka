#include <iostream>
#include <string>

#include "../Vehicles/bike.h"
#include "../Factory/factory.h"

#ifndef B_FACTORY_H
#define B_FACTORY_H

template <class T>
class BikeFactory : public Factory<T> {

public:

    explicit BikeFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency);

    void addNew(std::string color, bool basket, int gears);

    Bike * sell(const Bike &bike);
};

template <class T>
BikeFactory<T>::BikeFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency) : Factory<T>(brand, capacity, fuel_amount, efficiency){
}

template <class T>
void BikeFactory<T>::addNew(std::string color, bool basket, int gears) {

    std::string owner = "Fabryka";
    int capacity = 5;
    if(basket) {
        capacity += 10;
    }

    Bike bike = Bike(owner, std::move(color), this -> brand, basket, capacity, gears);
    this -> garage.push_back(bike);
}

template <class T>
Bike * BikeFactory<T>::sell(const Bike& bike) {

    for(int i = 0; i < this -> garage.size(); i++) {
        if(this -> garage.at(i) == bike) {
            Bike * tmp = new Bike("Fabryka", this -> garage.at(i).getColor(), this -> garage.at(i).getBrand(), this -> garage.at(i).isBasket(), this -> garage.at(i).getCapacity(), this -> garage.at(i).getGears());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }
    return nullptr;
}

#endif //B_FACTORY_H