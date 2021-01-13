#ifndef VARNISHER_H
#define VARNISHER_H

#include <iostream>
#include <string>
#include <fstream>
#include "Vehicles/vehicle.h"

template<class T>
class Varnisher {

public:

    static void changeColor(T &vehicle, std::ifstream &plik);
};

template<class T>
void Varnisher<T>::changeColor(T &vehicle, std::ifstream &plik) {

    std::string color;
    if(plik.is_open()) {
        plik >> color;
    } else {
        std::cout << "Podaj nowy kolor: " << std::endl;
        std::cin >> color;
    }
    vehicle.color = color;

    if(typeid(T) == typeid(Engine_Vehicle)) {
        std::cout << "Zmieniono kolor pojazdu o rejestracji " << vehicle.number<< " na " << color << "." << std::endl;
    } else {
        std::cout << "Zmieniono kolor pojazdu na " << color << "." << std::endl;
    }
}

#endif //VARNISHER_H