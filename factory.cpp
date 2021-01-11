#include "factory.h"

#include <utility>

Factory::Factory(std::string name) {
    this -> name = std::move(name);
}
    
void Factory::addNewCar(std::string color, int door_count, int brand) {
    int capacity;
    float fuel_amount;
    float efficiency;
    std::string brand_name;

    switch(brand) {
        case(1) : {
            capacity = 600;
            fuel_amount = 60;
            efficiency = 8.5;
            brand_name = "Audi";
            break;
        }
        case(2) : {
            capacity = 500;
            fuel_amount = 70;
            efficiency = 11.7;
            brand_name = "Mercedes";
            break;
        }
        case(3) : {
            capacity = 400;
            fuel_amount = 80;
            efficiency = 10.9;
            brand_name = "BMW";
            break;
        }
        default: {
            capacity = 0;
            fuel_amount = 0;
            efficiency = 0;
            brand_name = "Nieznana";
            break;
        }
    }

    Car car = Car(this -> name, std::move(color), brand_name, door_count, capacity, fuel_amount, efficiency);
    this -> garage.push_back(car);
}

Car * Factory::sell(const Car& car, const std::string& car_name) {
    for(int i = 0; i < this -> garage.size(); i++) {
        if(this -> garage.at(i) == car) {
            Car * tmp = new Car(car_name, this -> garage.at(i).getColor(), garage.at(i).getBrand(), this -> garage.at(i).getDoorCount(), this -> garage.at(i).getCapacity(), garage.at(i).getFuelAmount(), garage.at(i).getEfficiency());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }
    return nullptr;
}

void Factory::printNew() {
    std::cout << this -> garage.at(this->garage.size()-1) << std::endl;
}
