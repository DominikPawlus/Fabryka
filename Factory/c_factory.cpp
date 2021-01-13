#include "c_factory.h"

void CarFactory::addNew(std::string color, int door_count) {

    std::string owner = "Fabryka";
    Car car = Car(owner, std::move(color), this -> brand, door_count, this -> capacity, this -> fuel_amount, this -> efficiency);
    this -> garage.push_back(car);

}

Car * CarFactory::sell(const Car &car, const std::string &car_name) {

    for(int i = 0; i < this -> garage.size(); i++) {
        if(this -> garage.at(i) == car) {
            Car * tmp = new Car(vehicle_name, this -> garage.at(i).getColor(), garage.at(i).getBrand(), this -> garage.at(i).getDoorCount(), this -> garage.at(i).getCapacity(), garage.at(i).getFuelAmount(), garage.at(i).getEfficiency());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }
    return nullptr;
}

