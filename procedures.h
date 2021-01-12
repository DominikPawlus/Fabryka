#ifndef PROCEDURES_H
#define PROCEDURES_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Vehicles/car.h"
#include "Vehicles/motorcycle.h"


struct false_door_count {
    std::string msg = "Liczba drzwi musi być liczbą naturalną.";
};

struct car_no_exist {
    std::string msg = "Podany samochód nie istnieje.";
};

template <class T>
T loadEngineVehicleData(int W, int K);

template <class T>
T loadEngineVehicleDataFile(int W, std::ifstream &plik);

int findEngineVehicle(const Engine_Vehicle& car, std::vector<Engine_Vehicle> &garage);

#endif //PROCEDURES_H
