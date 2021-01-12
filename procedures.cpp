#include "procedures.h"

template <class T>
T loadEngineVehicleData(int W, int K) {

    std::string owner = "Gigafactory";
    std::string brand;
    std::string color;

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

    if(typeid(T) == typeid(Car)) {
        int door_count;
        std::cout << "Podaj liczbę drzwi: " << std::endl;
        std::cin >> door_count;
        if (std::cin.fail()) {
            std::cin.clear();

            false_door_count kapsula;
            throw kapsula;
        }

        Car tmp = Car(owner, color, brand, door_count, 0, 0, 0); //capacity = 0, fuel_amount = 0 nie ma znaczenia dla tmp
        return tmp;
    } else {
        Motorcycle tmp = Motorcycle(owner, color, brand, 0, 0, 0);
        return tmp;
    }
}

template <class T>
T loadEngineVehicleDataFile(int W, std::ifstream &plik) {

    std::string owner = "Gigafactory";
    std::string brand;
    std::string color;

    if(W == 3 || W == 4 || W == 6 || W == 7) {
        plik >> owner;
    }
    if(W != 1) {
        plik >> brand;
    }

    plik >> color;
    if(typeid(T) == typeid(Car)) {
        int door_count;
        plik >> door_count;

        if (plik.fail()) {
            false_door_count kapsula;
            throw kapsula;
        }

        Car tmp = Car(owner, color, brand, door_count, 0, 0, 0);
        return tmp;
    } else {
        Motorcycle tmp = Motorcycle(owner, color, brand, 0, 0, 0);
        return tmp;
    }
}

int findEngineVehicle(const Engine_Vehicle& car, std::vector<Engine_Vehicle> &garage) {

    for(int i = 0; i < garage.size(); i++) {
        if(car == garage.at(i)) {
            return i;
        }
    }

    car_no_exist kapsula;
    throw kapsula;
}