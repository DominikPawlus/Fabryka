#include <iostream>
#include <string>
#include <vector>

#ifndef FACTORY_H
#define FACTORY_H

template <class T>
class Factory {
    private:
        std::vector<T> garage;
        std::string brand;
        int capacity;
        float fuel_amount;
        float efficiency;

    public:

        explicit Factory(const std::string& brand, int capacity, float fuel_amount, float efficiency);

};

#endif //FACTORY_H