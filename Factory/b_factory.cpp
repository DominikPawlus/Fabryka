#include "b_factory.h"

void BikeFactory::addNew(std::string color, bool basket) {

    std::string owner = "Fabryka";
    int capacity = 5;
    if(basket) {
        capacity += 10;
    }

    Bike bike = Bike(owner, std::move(color), this -> brand, basket, cpacity);
    this -> garage.push_back(bike);
}

Bike * BikeFactory::sell(const Bike& bike, const std::string& bike_name) {

    for(int i = 0; i < this -> garage.size(); i++) {
        if(this -> garage.at(i) == bike) {
            Bike * tmp = new Bike(vehicle_name, this -> garage.at(i).getColor(), garage.at(i).getBrand(), this -> garage.at(i).isBasket(), this -> garage.at(i).getCapacity());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }
    return nullptr;
}