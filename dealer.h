#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <vector>
#include "Vehicles/car.h"
#include "procedures.h"

template<class T>
class Dealer {

private:

    std::vector<T> parking;

public:

    Dealer();

    int buyPrice(T car);

    int sellPrice(T car);

    void buyCar(const T& car, std::vector<T> &garage);

    void sellCar(const T& car, const std::string& new_owner, std::vector<T> &garage);

};


    template<class T>
    Dealer<T>::Dealer() = default;

    template<class T>
    int Dealer<T>::buyPrice(T car) {

        int price;
        if (car.getBrand() == "Audi") {
            price = 200000;
        }
        if (car.getBrand() == "Mercedes") {
            price = 300000;
        }
        if (car.getBrand() == "BMW") {
            price = 250000;
        }

        if(typeid(T) == typeid(Car)) {
            price -= car.getMileage() / 2;
        } else {
            price /= 4;
        }

        return price;
    }

    template<class T>
    int Dealer<T>::sellPrice(T car){

        int price;
        price = buyPrice(car);
        price += price / 5;

        return price;
    }

    template<class T>
    void Dealer<T>::buyCar(const T& car, std::vector<T> &garage){

        for(int i = 0; i < garage.size(); i++) {
            if(car == garage.at(i)) {
                std::cout << "Sprzedałeś samochód: " << std::endl << garage.at(i) << std::endl << "za " << buyPrice(garage.at(i)) << " zł" << std::endl;
                garage.at(i).owner = "Komis";
                if(garage.at(i).getBrand() == "BMW") {
                    garage.at(i).splitMileage();
                }
                this -> parking.push_back(garage.at(i));
                garage.erase(garage.begin() + i);
            }
        }
    }

    template<class T>
    void  Dealer<T>::sellCar(const T& car, const std::string& new_owner, std::vector<T> &garage) {

        for(int i = 0; i < this -> parking.size(); i++) {
            if(car == parking.at(i)) {
                parking.at(i).owner = new_owner;
                std::cout << "Kupiłeś samochód: " << std::endl << parking.at(i) << std::endl << "za " << sellPrice(parking.at(i)) << " zł" << std::endl;
                garage.push_back(parking.at(i));
                parking.erase(parking.begin() + i);
            }
        }
    }

#endif //DEALER_H







