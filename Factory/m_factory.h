#include <iostream>
#include <string>

#include "../Vehicles/motorcycle.h"
#include "../Factory/factory.h"

#ifndef M_FACTORY_H
#define M_FACTORY_H

template <class T>
class MotorFactory : public Factory<T> {

public:

    explicit MotorFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency);

    void addNew(std::string color);

    Motorcycle * sell(const Motorcycle &motor);
};

template <class T>
MotorFactory<T>::MotorFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency) : Factory<T>(brand, capacity, fuel_amount, efficiency){
}

template <class T>
void MotorFactory<T>::addNew(std::string color) {

    std::string owner = "Fabryka";
    Motorcycle motor = Motorcycle(owner, std::move(color), this -> brand, this -> capacity, this -> fuel_amount, this -> efficiency);
    this -> garage.push_back(motor);

}

template <class T>
Motorcycle * MotorFactory<T>::sell(const Motorcycle& motor) {

    for(int i = 0; i < this -> garage.size(); i++) {
        if(this -> garage.at(i) == motor) {
            Motorcycle * tmp = new Motorcycle("Fabryka", this -> garage.at(i).getColor(), this -> garage.at(i).getBrand(), this -> garage.at(i).getCapacity(), this -> garage.at(i).getFuelAmount(), this -> garage.at(i).getEfficiency());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }
    return nullptr;
}

#endif //M_FACTORY_H