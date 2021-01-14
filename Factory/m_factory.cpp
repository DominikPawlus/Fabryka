#include "m_factory.h"

template <class T>
MotorFactory<T>::MotorFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency) {
    this -> brand = std::move(brand);
    this -> capacity = capacity;
    this -> fuel_amount = fuel_amount;
    this -> efficiency - efficiency;
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