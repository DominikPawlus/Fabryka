#include "bike.h"

Bike::Bike(std::string owner, std::string color, std::string brand, bool basket, int capacity) : Vehicle(owner, color, brand, capacity), basket(basket) {
}

bool Bike::isBasket() {
    return this -> basket;
}

float Bike::go(float km) {
            this -> mileage += km;
            float kalorie = km * (25 + 20 / this -> gears);
            std::cout << "Przejechałeś " << km << " kilometrów rowerem." << std::endl;
            std::cout << "Spaliłeś " << kalorie << " kalorii." << std::endl;
            return this -> mileage;
};