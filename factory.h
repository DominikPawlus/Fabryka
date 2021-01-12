#include <iostream>
#include <string>
#include <vector>

#include "Vehicles/engine_vehicle.h"
#include "Vehicles/car.h"
#include "Vehicles/motorcycle.h"

#ifndef FACTORY_H
#define FACTORY_H

template <class T>
class Factory {
    private:
        std::string name;
        std::vector<T> garage;

    public:

        explicit Factory(std::string name = "Gigafactory");
    
        void addNewVehicle(std::string color, int door_count, int brand);

        T * sell(const T& car, const std::string& owner);

        void printNew();
};

template <class T>
T * Factory<T>::sell(const T& car, const std::string& owner) {
    for(int i = 0; i < this -> garage.size(); i++) {
        if(this -> garage.at(i) == car) {
            if(typeid(T) == typeid(Car)) {
                T *tmp = new Car(owner, this -> garage.at(i).getColor(), garage.at(i).getBrand(), garage.at(i).getDoorCount(), this -> garage.at(i).getCapacity(), garage.at(i).getFuelAmount(), garage.at(i).getEfficiency());
                this -> garage.erase(this -> garage.begin() + i);
                return tmp;
            }
        }
    }
    return nullptr;
}

template <class T>
void Factory<T>::addNewVehicle(std::string color, int door_count, int brand) {
    int capacity;
    float fuel_amount;
    float efficiency;
    std::string brand_name;

    switch(brand) {
        case(1) : {
            capacity = 600;
            fuel_amount = 60;
            efficiency = 8.5;
            brand_name = "Audi";
            break;
        }
        case(2) : {
            capacity = 500;
            fuel_amount = 70;
            efficiency = 11.7;
            brand_name = "Mercedes";
            break;
        }
        case(3) : {
            capacity = 400;
            fuel_amount = 80;
            efficiency = 10.9;
            brand_name = "BMW";
            break;
        }
        default: {
            capacity = 0;
            fuel_amount = 0;
            efficiency = 0;
            brand_name = "Nieznana";
            break;
        }
    }

    Car car = Car(this -> name, std::move(color), brand_name, door_count, capacity, fuel_amount, efficiency);
    this -> garage.push_back(car);
}

template <class T>
Factory<T>::Factory(std::string name) {
    this -> name = std::move(name);
}

template <class T>
void Factory<T>::printNew() {
    std::cout << this -> garage.at(this->garage.size()-1) << std::endl;
}

#endif //FACTORY_H