#include "procedures.h"

template <class T>
T * loadData(int W, int K, std::ifstream &plik) {

    std::string owner;
    std::string brand;
    std::string color;
    int door_count;

    if(plik.is_open()){

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
    } else {

        if ((W == 3 || W == 4 || W == 6 || W == 7) && K != 2) {
            std::cout << "Podaj właściciela: " << std::endl;
            std::cin >> owner;
        }
        if (W != 1) {
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
    }

    if(typeid(T) == typeid(Car)) {
        T *tmp = Car(owner, color, brand, door_count, 0, 0, 0);
        return *tmp;
    }
    if(typeid(T) == typeid(Motorcycle)) {
        T *tmp = Motorcycle(owner, color, brand, 0, 0, 0);
        return *tmp;
    }
    if(typeid(T) == typeid(Bike)) {
        T *tmp = Bike(owner, color, brand, 0, 0);
        return *tmp;
    }
}

template <class T>
int findVehicle(T vehicle, std::vector<T> &garage) {

    for(int i = 0; i < garage.size(); i++) {
        if(vehicle == garage.at(i)) {
            return i;
        }
    }

    car_no_exist kapsula;
    throw kapsula;
}