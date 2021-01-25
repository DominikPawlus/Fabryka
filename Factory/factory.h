#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "procedures.h"

#ifndef FACTORY_H
#define FACTORY_H

template <class T>
class Factory {

protected:
    std::vector<T> garage;
    std::string brand;
    int capacity;
    float fuel_amount;
    float efficiency;

public:

    Factory() = default;

    Factory(std::string  brand, int capacity, float fuel_amount, float efficiency) :
    brand(std::move(brand)), capacity(capacity), fuel_amount(fuel_amount), efficiency(efficiency){
    }

};

#endif //FACTORY_H