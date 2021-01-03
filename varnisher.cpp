#include "varnisher.h"

void Varnisher::changeColor(Vehicle &vehicle) {

    std::string color;
    std::cout << "Podaj nowy kolor: " << std::endl;
    std::cin >> color;
    vehicle.color = color;
    std::cout << "Zmieniono kolor na " << color << std::endl;
}