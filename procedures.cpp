#include "procedures.h"

Car loadCarData(int W, std::ifstream &plik) {

    std::string owner = "Fabryka";
    std::string brand;
    std::string color;
    int door_count;
    int J;

    if(plik.is_open()){

        if(W != 1 && W != 2) {
            plik >> owner;
        }
        if(W != 1 && W != 2) {
            plik >> J;
        }

        plik >> color;
        plik >> door_count;
        if (plik.fail()) {
            false_door_count kapsula;
            throw kapsula;
        }
    } else {

        if(W != 1 && W != 2) {
            std::cout << "Podaj właściciela: " << std::endl;
            std::cin >> owner;
        }

        std::cout << "Wybierz markę samochodu: " << std::endl;
        std::cout << "(1) - BMW" << std::endl << "(2) - Audi" << std::endl << "(3) - Mercedes" << std::endl;
        std::cin >> J;
        std::cout << "Podaj kolor: " << std::endl;
        std::cin >> color;
        std::cout << "Podaj liczbę drzwi: ";
        std::cin >> door_count;

        if (std::cin.fail()) {
            std::cin.clear();
            false_door_count kapsula;
            throw kapsula;
        }
    }

    if(J == 1) {
        brand = "BMW";
    }
    if(J == 2) {
        brand = "Audi";
    }
    if(J == 3) {
        brand = "Mercedes";
    }

    Car tmp = Car(owner, color, brand, door_count, 0, 0, 0);
    return tmp;
}

Motorcycle loadMotorData(int W, std::ifstream &plik) {

    std::string owner = "Fabryka";
    std::string brand;
    std::string color;
    int J;

    if(plik.is_open()){

        if(W != 1) {
            plik >> owner;
        }
        if(W != 1) {
            plik >> J;
        }

        plik >> color;
    } else {

        if(W != 1) {
            std::cout << "Podaj właściciela: " << std::endl;
            std::cin >> owner;
        }

        std::cout << "Wybierz markę motocykla: " << std::endl;
        std::cout << "(1) - Kawasaki" << std::endl << "(2) - Honda" << std::endl;
        std::cin >> J;
        std::cout << "Podaj kolor: " << std::endl;
        std::cin >> color;
        }

    if(J == 1) {
        brand = "Kawasaki";
    }
    if(J == 2) {
        brand = "Honda";
    }

    Motorcycle tmp = Motorcycle(owner, color, brand, 0, 0, 0);

    return tmp;
}

Bike loadBikeData(int W, std::ifstream &plik) {

    std::string owner = "Fabryka";
    std::string brand = "Romet";
    std::string color;
    bool basket;
    int J;

    if(plik.is_open()){

        if(W != 1) {
            plik >> owner;
        }

        plik >> color >> J;
    } else {

        if(W != 1) {
            std::cout << "Podaj właściciela: " << std::endl;
            std::cin >> owner;
        }

        std::cout << "Podaj kolor: " << std::endl;
        std::cin >> color;
        std::cout << "Czy rower posiada koszyk?";
        std::cout << "(1) - tak" << std::endl << "(2) - nie" << std::endl;
        std::cin >> J;
    }

    if(J == 1) {
        basket = true;
    }
    if(J == 2) {
        basket = false;
    }

    Bike tmp = Bike(owner, color, brand, basket, 0);

    return tmp;
}

