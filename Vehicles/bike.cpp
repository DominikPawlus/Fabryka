#include "bike.h"

Bike::Bike(std::string owner, std::string color, std::string brand, bool basket, int capacity) : Vehicle(owner, color, brand, capacity), basket(basket) {
}

bool Bike::isBasket() {
    return this -> basket;
}