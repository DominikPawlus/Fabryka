#ifndef PROCEDURES_H
#define PROCEDURES_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Vehicles/car.h"


struct false_door_count {
    std::string msg = "Liczba drzwi musi być liczbą naturalną.";
};

struct car_no_exist {
    std::string msg = "Podany samochód nie istnieje.";
};

Car loadCarData(int W, int K);

Car loadCarDataFile(int W, std::ifstream &plik);

Car findCar(Car car, std::vector<Car> &garage);

#endif //PROCEDURES_H
