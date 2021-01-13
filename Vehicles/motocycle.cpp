#include <utility>

#include "motorcycle.h"

Motorcycle::Motorcycle(std::string owner, std::string color, std::string brand, int capacity, float fuel_amount, float efficiency)
    : Engine_Vehicle(std::move(owner), std::move(color), std::move(brand), capacity, fuel_amount, efficiency) {
}

std::ostream& operator<<(std::ostream& out, const Motorcycle& motor) {
    out << "Właściciel: " << motor.owner << std::endl << "Kolor: " << motor.color << std::endl <<
        "Marka: " << motor.brand << std::endl <<
        "Przebieg: " << motor.mileage << std::endl << "Ładowność: " << motor.capacity << " kg" << std::endl <<
        "Ilość paliwa: " << motor.fuel_amount << " l" << std::endl << "Spalanie: " << motor.efficiency << " l/100km" << std::endl;
    return out;
}

bool operator==(const Motorcycle& motor1, const Motorcycle& motor2) { //operator porównania jest przeładowany dla każdej klasy w razie dodania nowych pól
    if(motor1.owner == motor2.owner && motor1.color == motor2.color && motor1.brand == motor2.brand) {
        return true;
    } else {
        return false;
    }
}