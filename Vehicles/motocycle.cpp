#include "motorcycle.h"

Motorcycle::Motorcycle(std::string owner, std::string color, std::string brand, int capacity, float fuel_amount, float efficiency)
    : Engine_Vehicle(owner, color, brand, capacity, fuel_amount, efficiency) {
}