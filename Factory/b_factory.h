#include <iostream>
#include <string>

#include "../Vehicles/bike.h"
#include "../Factory/factory.h"

#ifndef B_FACTORY_H
#define B_FACTORY_H

template <class T>
class BikeFactory : public Factory<T> {

public:

    explicit BikeFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency);

    void addNew(std::string color, bool basket);

    Bike * sell(const Bike &motor);
};

#endif //B_FACTORY_H