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


Car * loadCarData(int W, std::ifstream &plik);

Motorcycle * loadMotorData(int W, std::ifstream &plik);

Bike * loadBikeData(int W, std::ifstream &plik);

template <typename T>
int findVehicle(T vehicle, std::vector<T> &garage);

template <typename T>
int findNumber(std::vector<T> garage, const std::string& number);

#endif //PROCEDURES_H
