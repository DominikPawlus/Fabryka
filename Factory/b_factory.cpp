#include "b_factory.h"

template <class T>
BikeFactory<T>::BikeFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency) {
    this -> brand = std::move(brand);
    this -> capacity = capacity;
    this -> fuel_amount = fuel_amount;
    this -> efficiency - efficiency;
}

template <class T>
void BikeFactory<T>::addNew(std::string color, bool basket) {

    std::string owner = "Fabryka";
    int capacity = 5;
    if(basket) {
        capacity += 10;
    }

    Bike bike = Bike(owner, std::move(color), this -> brand, basket, capacity);
    this -> garage.push_back(bike);
}

template <class T>
Bike * BikeFactory<T>::sell(const Bike& bike) {

    for(int i = 0; i < this -> garage.size(); i++) {
        if(this -> garage.at(i) == bike) {
            Bike * tmp = new Bike("Fabryka", this -> garage.at(i).getColor(), this -> garage.at(i).getBrand(), this -> garage.at(i).isBasket(), this -> garage.at(i).getCapacity());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }
    return nullptr;
}