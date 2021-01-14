#include "bike.h"

Bike::Bike(std::string owner, std::string color, std::string brand, bool basket, int capacity, int gears) : Vehicle(owner, color, brand, capacity), basket(basket), gears(gears) {
}

float Bike::go(float km) {
            this -> mileage += km;
            float kalorie = km * (25 + 20 / this -> gears);
            std::cout << "Przejechałeś " << km << " kilometrów rowerem." << std::endl;
            std::cout << "Spaliłeś " << kalorie << " kalorii." << std::endl;
            return this -> mileage;
};

bool Bike::isBasket() const {
    return this -> basket;
}

int Bike::getGears() const {
    return this -> gears;
}