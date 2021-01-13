#include "m_factory.h"

void MotorFactory::addNew(std::string color, int door_count) {

    std::string owner = "Fabryka";
    Motorcycle motor = Motorcycle(owner, std::move(color), this -> brand, this -> capacity, this -> fuel_amount, this -> efficiency);
    this -> garage.push_back(car);

}

Motorcycle * MotorFactory::sell(const Motorcycle& motor, const std::string& motor_name) {

    for(int i = 0; i < this -> garage.size(); i++) {
        if(this -> garage.at(i) == motor) {
            Motorcycle * tmp = new Motorcycle(vehicle_name, this -> garage.at(i).getColor(), garage.at(i).getBrand(), this -> garage.at(i).getCapacity(), garage.at(i).getFuelAmount(), garage.at(i).getEfficiency());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }
    return nullptr;
}