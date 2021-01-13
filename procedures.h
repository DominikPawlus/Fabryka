#ifndef PROCEDURES_H
#define PROCEDURES_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Vehicles/car.h"
#include "Vehicles/motorcycle.h"
#include "Vehicles/bike.h"


struct false_door_count {
    std::string msg = "Liczba drzwi musi być liczbą naturalną.";
};

struct car_no_exist {
    std::string msg = "Podany samochód nie istnieje.";
};

template <class T>
T * loadData(int W, int K, std::ifstream &plik);

template <class T>
int findVehicle(T vehicle, std::vector<T> &garage);

#endif //PROCEDURES_H
