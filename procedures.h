#ifndef PROCEDURES_H
#define PROCEDURES_H

#include <iostream>
#include <string>
#include <fstream>
#include "Vehicles/car.h"

Car loadCarData(int W, int K);

Car loadCarDataFile(int W, int K, std::ifstream &plik);

#endif //PROCEDURES_H
