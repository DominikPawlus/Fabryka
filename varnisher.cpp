#include "varnisher.h"

void Varnisher::changeColor(Vehicle &vehicle, std::ifstream &plik) {

    std::string color;
    if(plik.is_open()) {
        plik >> color;
    } else {
        std::cout << "Podaj nowy kolor: " << std::endl;
        std::cin >> color;
    }
    vehicle.color = color;
    std::cout << "Zmieniono kolor na " << color << std::endl;
}