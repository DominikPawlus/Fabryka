#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car {

    private:
    std::string owner;
    std::string color;
    const std::string brand;
    const int door_count;
    int mileage;

    public:
    Car(std::string owner, std::string color, std::string brand, int door_count, int mileage = 0);

    friend std::ostream& operator<<(std::ostream& out, const Car& car);

    friend bool operator==(const Car& car1, const Car& car2);

    int go(int km);

    std::string getColor();

    int getDoorCount();
};

#endif //CAR_H