#include <iostream>
#include <string>
#include <vector>

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

        Factory(const std::string& brand, int capacity, float fuel_amount, float efficiency) :
        brand(brand), capacity(capacity), fuel_amount(fuel_amount), efficiency(efficiency){
        }

};

#endif //FACTORY_H