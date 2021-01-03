#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <vector>
#include "engine_vehicle.h"

class Car : public Engine_Vehicle {

    private:
    int door_count;

    public:

    Car(std::string owner, std::string color, std::string brand, int door_count, int capacity, float fuel_amount, float efficiency);

    friend std::ostream& operator<<(std::ostream& out, const Car& car);

    friend bool operator==(const Car& car1, const Car& car2);

    int go(float km, std::vector<Car> &garage);

    int getDoorCount() const;

    void splitMileage();
};

#endif //CAR_H