#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <vector>
#include "../Vehicles/vehicle.h"
#include "../procedures.h"

template<class T>
class Dealer {

private:

    std::vector<T*> parking;

public:

    Dealer();

    int buyPrice(T vehicle);
    int sellPrice(T vehicle);
    void buy(const T& vehicle, std::vector<T*> &garage);
    void sell(const T& vehicle, const std::string& new_owner, std::vector<T*> &garage);

    int getParkSize();
    std::vector<T*> showParking();

};

    template<class T>
    Dealer<T>::Dealer() = default;

    template<class T>
    int Dealer<T>::buyPrice(T vehicle) {

        int price;

        if (vehicle.getBrand() == "Audi") {
            price = 200000;
        }
        if (vehicle.getBrand() == "Mercedes") {
            price = 300000;
        }
        if (vehicle.getBrand() == "BMW") {
            price = 250000;
        }
        if (vehicle.getBrand() == "Kawasaki") {
            price = 80000;
        }
        if (vehicle.getBrand() == "Honda") {
            price = 40000;
        }
        if (vehicle.getBrand() == "Romet") {
            price = 3000;
        }

        price -= vehicle.getMileage() / 2;

        return price;
    }

    template<class T>
    int Dealer<T>::sellPrice(T vehicle){

        int price;
        price = buyPrice(vehicle);
        price += price / 5;

        return price;
    }

    template<class T>
    void Dealer<T>::buy(const T& vehicle, std::vector<T*> &garage){

        for(int i = 0; i < garage.size(); i++) {
            if(vehicle == *garage.at(i)) {
                std::cout << "Sprzedałeś pojazd: " << std::endl << garage.at(i) << std::endl << "za " << buyPrice(*garage.at(i)) << " zł." << std::endl;
                garage.at(i)->owner = "Komis";

                if(garage.at(i)->getBrand() == "BMW" || garage.at(i)->getBrand() == "Honda") {
                    garage.at(i)->splitMileage();
                }

                this -> parking.push_back(garage.at(i));
                garage.erase(garage.begin() + i);
            }
        }
    }

    template<class T>
    void  Dealer<T>::sell(const T& vehicle, const std::string& new_owner, std::vector<T*> &garage) {

        for(int i = 0; i < this -> parking.size(); i++) {
            if(vehicle == *parking.at(i)) {
                parking.at(i)->owner = new_owner;

                    std::cout << "Kupiłeś pojazd: " << std::endl << parking.at(i) << std::endl << "za " << sellPrice(*parking.at(i)) << " zł" << std::endl;

                garage.push_back(parking.at(i));
                parking.erase(parking.begin() + i);
            }
        }
    }

template<class T>
int Dealer<T>::getParkSize() {
    return this -> parking.size();
}

template<class T>
std::vector<T*> Dealer<T>::showParking() {
    return this -> parking;
}


#endif //DEALER_H







