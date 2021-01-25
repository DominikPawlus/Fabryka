#include "procedures.h"

Car* loadCarData(int W, std::ifstream &plik) {

    std::string owner = "Fabryka";
    std::string brand;
    std::string color;
    int door_count;
    int J; //wybór marki

    if(plik.is_open()) {

        if(W != 1 && W != 2) {
            plik >> owner;
        }

        plik >> J;
        if (plik.fail()) {
            false_brand kapsula;
            throw kapsula;
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

        if (std::cin.fail()) {
            std::cin.clear();
            false_brand kapsula;
            throw kapsula;
        }

        std::cout << "Podaj liczbę drzwi: " << std::endl;
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

    Car* tmp = new Car(owner, color, brand, door_count, 0, 0, 0);
    return tmp;
}

Motorcycle* loadMotorData(int W, std::ifstream &plik) {

    std::string owner = "Fabryka";
    std::string brand;
    std::string color;
    int J; //wybór marki

    if(plik.is_open()){

        if(W != 1 && W != 2) {
            plik >> owner;
        }

        plik >> J;
        if (plik.fail()) {
            false_brand kapsula;
            throw kapsula;
        }

        plik >> color;
    } else {

        if(W != 1 && W != 2) {
            std::cout << "Podaj właściciela: " << std::endl;
            std::cin >> owner;
        }

        std::cout << "Wybierz markę motocykla: " << std::endl;
        std::cout << "(1) - Kawasaki" << std::endl << "(2) - Honda" << std::endl;
        std::cin >> J;

        if (std::cin.fail()) {
            std::cin.clear();
            false_brand kapsula;
            throw kapsula;
        }

        std::cout << "Podaj kolor: " << std::endl;
        std::cin >> color;
        }

    if(J == 1) {
        brand = "Kawasaki";
    }
    if(J == 2) {
        brand = "Honda";
    }

    Motorcycle* tmp = new Motorcycle(owner, color, brand, 0, 0, 0);
    return tmp;
}

Bike* loadBikeData(int W, std::ifstream &plik) {

    std::string owner = "Fabryka";
    std::string brand = "Romet";
    std::string color;
    bool basket;
    int gears;
    int J; //koszyk

    if(plik.is_open()){

        if(W != 1 && W != 2) {
            plik >> owner;
        }

        plik >> color;

        plik >> J;
        if (plik.fail()) {
            false_brand kapsula;
            throw kapsula;
        }

        plik >> gears;
    } else {

        if(W != 1 && W != 2) {
            std::cout << "Podaj właściciela: " << std::endl;
            std::cin >> owner;
        }

        std::cout << "Podaj kolor: " << std::endl;
        std::cin >> color;
        std::cout << "Czy rower posiada koszyk?" << std::endl;
        std::cout << "(1) - tak" << std::endl << "(2) - nie" << std::endl;
        std::cin >> J;

        if (std::cin.fail()) {
            std::cin.clear();
            false_brand kapsula;
            throw kapsula;
        }

        std::cout << "Podaj liczbę przełożeń:" << std::endl;
        std::cin >> gears;
    }

    if(J == 1) {
        basket = true;
    }
    if(J == 2) {
        basket = false;
    }

    Bike* tmp = new Bike(owner, color, brand, basket, 0, gears);
    return tmp;
}

