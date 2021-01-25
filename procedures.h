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

struct vehicle_no_exist {
    std::string msg = "Podany samochód nie istnieje.";
};

struct false_brand {
    std::string msg = "Podaj poprawny numer marki.";
};


Car loadCarData(int W, std::ifstream &plik);

Motorcycle loadMotorData(int W, std::ifstream &plik);

Bike loadBikeData(int W, std::ifstream &plik);

template <typename T>
int findVehicle(T vehicle, std::vector<T> &garage) {

    for(int i = 0; i < garage.size(); i++) {
        if(vehicle == garage.at(i)) {
            return i;
        }
    }

    vehicle_no_exist kapsula;
    throw kapsula;
}

template <typename T>
int findNumber(std::vector<T> &garage, const std::string& number) {

    for(int i = 0; i < garage.size(); i++) {
        if(number == garage.at(i).number) {
            return i;
        }
    }

    vehicle_no_exist kapsula;
    throw kapsula;
}

#endif //PROCEDURES_H
