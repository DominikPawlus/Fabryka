#include "c_factory.h"

template <class T>
CarFactory<T>::CarFactory(const std::string& brand, int capacity, float fuel_amount, float efficiency) {
    this -> brand = std::move(brand);
    this -> capacity = capacity;
    this -> fuel_amount = fuel_amount;
    this -> efficiency - efficiency;
}

template <class T>
void CarFactory<T>::addNew(std::string color, int door_count) {

    std::string owner = "Fabryka";
    Car car = Car(owner, std::move(color), this -> brand, door_count, this -> capacity, this -> fuel_amount, this -> efficiency);
    this -> garage.push_back(car);

}

template <class T>
Car * CarFactory<T>::sell(const Car &car) {

    for(int i = 0; i < this -> garage.size(); i++) {
        if(this -> garage.at(i) == car) {
            Car * tmp = new Car("Fabryka", this -> garage.at(i).getColor(), this -> garage.at(i).getBrand(), this -> garage.at(i).getDoorCount(), this -> garage.at(i).getCapacity(), this -> garage.at(i).getFuelAmount(), this -> garage.at(i).getEfficiency());
            this -> garage.erase(this -> garage.begin() + i);
            return tmp;
        }
    }
    return nullptr;
}

