#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car {

    public:
    std::string owner;
    std::string color;
    const std::string brand;
    const int door_count;
    int mileage;

    Car(std::string owner, std::string color, std::string brand, int door_count, int mileage = 0);

    std::ostream& operator<<(std::ostream& out, const Car& car);

    int go(int km);
};

#endif //CAR_H