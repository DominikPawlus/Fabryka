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

#endif //C_FACTORY_H