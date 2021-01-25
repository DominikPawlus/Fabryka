#include <iostream>
#include <string>

#include "../Vehicles/car.h"
#include "../Factory/factory.h"

#ifndef C_FACTORY_H
#define C_FACTORY_H

template <class Car>
class CarFactory : public Factory<Car> {

public:

    explicit CarFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency);

    void addNew(const std::string& color, int door_count);

    Car * sell(const Car &car);

};

template <class Car>
CarFactory<Car>::CarFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency) : Factory<Car>(brand, capacity, fuel_amount, efficiency){
}

template <class Car>
void CarFactory<Car>::addNew(const std::string& color, int door_count) {

    std::string owner = "Fabryka";
    Car *car = new Car(owner, color, this -> brand, door_count, this -> capacity, this -> fuel_amount, this -> efficiency);
    this -> garage.push_back(*car);
}

template <class Car>
Car * CarFactory<Car>::sell(const Car &car) {

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

#endif //C_FACTORY_H