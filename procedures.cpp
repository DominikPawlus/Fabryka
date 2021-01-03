#include "procedures.h"

Car loadCarData(int W, int K) {

    std::string owner = "Gigafactory";
    std::string brand;
    std::string color;
    int door_count;

    if((W == 3 || W == 4 || W == 6 || W == 7) && K != 2) {
        std::cout << "Podaj właściciela: " << std::endl;
        std::cin >> owner;
    }
    if(W != 1) {
        std::cout << "Podaj markę: " << std::endl;
        std::cin >> brand;
    }

    std::cout << "Podaj kolor: " << std::endl;
    std::cin >> color;
    std::cout << "Podaj liczbę drzwi: " << std::endl;
    std::cin >> door_count;

    Car tmp = Car(owner, color, brand, door_count, 0, 0, 0); //capacity = 0, fuel_amount = 0 nie ma znaczenia dla tmp

    return tmp;
}