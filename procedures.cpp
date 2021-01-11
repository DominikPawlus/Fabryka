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
    if (std::cin.fail()) {
        std::cin.clear();

        false_door_count kapsula;
        throw kapsula;
    }

    Car tmp = Car(owner, color, brand, door_count, 0, 0, 0); //capacity = 0, fuel_amount = 0 nie ma znaczenia dla tmp

    return tmp;
}

Car loadCarDataFile(int W, std::ifstream &plik) {

    std::string owner = "Gigafactory";
    std::string brand;
    std::string color;
    int door_count;

    if(W == 3 || W == 4 || W == 6 || W == 7) {
        plik >> owner;
    }
    if(W != 1) {
        plik >> brand;
    }

    plik >> color;
    plik >> door_count;
    if (plik.fail()) {
        false_door_count kapsula;
        throw kapsula;
    }

    Car tmp = Car(owner, color, brand, door_count, 0, 0, 0); //capacity = 0, fuel_amount = 0 nie ma znaczenia dla tmp

    return tmp;
}

int findCar(Car car, std::vector<Car> &garage) {

    for(int i = 0; i < garage.size(); i++) {
        if(car == garage.at(i)) {
            return i;
        }
    }

    car_no_exist kapsula;
    throw kapsula;
}