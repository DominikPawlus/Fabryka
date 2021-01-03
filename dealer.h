#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <vector>
#include "Vehicles/car.h"
#include "procedures.h"

class Dealer {

private:
    std::vector<Car> parking;

public:

    Dealer();

    static int buyPrice(Car car);

    static int sellPrice(Car car);

    void buy(const Car& car, std::vector<Car> &garage);

    void sell(const Car& car, const std::string& owner, std::vector<Car> &garage);

};

#endif //DEALER_H