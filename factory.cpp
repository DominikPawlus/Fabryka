#include "factory.h"

Factory::Factory(std::string name) {
    this -> name = name;
}
    
void Factory::addNewCar(std::string color, int door_count) {
    Car car = Car("Factory", color, this -> name, door_count);
    this -> garage.push_back(car);
}

Car * Factory::sell(Car car, std::string name) {
    for(int i = 0; i < this -> garage.size(); i++){
        if(this -> garage.at(i) == car){
            Car * tmp = new Car(name, garage.at(i).getColor(),this->name,garage.at(i).getDoorCount());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }
    return nullptr;
}

void Factory::print(){
    for(int i = 0; i < this->garage.size(); i++) {
        std::cout << this -> garage.at(i) << std::endl;
    }
}

void Factory::printNew(){
    std::cout << this -> garage.at(this->garage.size()-1) << std::endl;
}