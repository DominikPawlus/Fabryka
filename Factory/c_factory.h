#include <iostream>
#include <string>

#include "../Vehicles/car.h"
#include "../Factory/factory.h"

#ifndef C_FACTORY_H
#define C_FACTORY_H

template <class T>
class CarFactory : public Factory<T> {

public:

    explicit CarFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency);

    void addNew(std::string color, int door_count);

    Car * sell(const Car &car);

};

template <class T>
CarFactory<T>::CarFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency) : Factory<T>(brand, capacity, fuel_amount, efficiency){
}

template <class T>
void CarFactory<T>::addNew(std::string color, int door_count) {

    std::string owner = "Fabryka";
    std::cout << door_count << std::endl;
    Car *car = new Car(owner, std::move(color), this -> brand, door_count, this -> capacity, this -> fuel_amount, this -> efficiency);
    this -> garage.push_back(*car);
}

template <class T>
Car * CarFactory<T>::sell(const Car &car) {

    for(int i = 0; i < this -> garage.size(); i++) {

        if(this -> garage.at(i) == car) {
            Car * tmp = new Car("Fabryka", this -> garage.at(i).getColor(), this -> garage.at(i).getBrand(), this -> garage.at(i).getDoorCount(), this -> garage.at(i).getCapacity(), this -> garage.at(i).getFuelAmount(), this -> garage.at(i).getEfficiency());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }
    return nullptr;
}

#endif //C_FACTORY_H