#include "factory.h"

template<class T>
Factory<T>::Factory(const std::string& brand, int capacity, float fuel_amount, float efficiency) {
    this -> brand = std::move(brand);
    this -> capacity = capacity;
    this -> fuel_amount = fuel_amount;
    this -> efficiency - efficiency;
}