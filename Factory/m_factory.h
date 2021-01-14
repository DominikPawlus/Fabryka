#include <iostream>
#include <string>

#include "../Vehicles/motorcycle.h"
#include "../Factory/factory.h"

#ifndef M_FACTORY_H
#define M_FACTORY_H

template <class T>
class MotorFactory : public Factory<T> {

public:

    explicit MotorFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency);

    void addNew(std::string color);

    Motorcycle * sell(const Motorcycle &motor);
};

#endif //M_FACTORY_H