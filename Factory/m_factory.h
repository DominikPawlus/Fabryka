#include <iostream>
#include <string>

#include "../Vehicles/motorcycle.h"
#include "../Factory/factory.h"

#ifndef M_FACMotorcycleORY_H
#define M_FACMotorcycleORY_H

template <class Motorcycle>
class MotorFactory : public Factory<Motorcycle> {

public:

    explicit MotorFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency);

    void addNew(std::string color);

    Motorcycle * sell(const Motorcycle &motor);
};

template <class Motorcycle>
MotorFactory<Motorcycle>::MotorFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency) : Factory<Motorcycle>(brand, capacity, fuel_amount, efficiency){
}

template <class Motorcycle>
void MotorFactory<Motorcycle>::addNew(std::string color) {

    std::string owner = "Fabryka";
    Motorcycle motor = Motorcycle(owner, std::move(color), this -> brand, this -> capacity, this -> fuel_amount, this -> efficiency);
    this -> garage.push_back(motor);

}

template <class Motorcycle>
Motorcycle * MotorFactory<Motorcycle>::sell(const Motorcycle& motor) {

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

#endif //M_FACMotorcycleORY_H