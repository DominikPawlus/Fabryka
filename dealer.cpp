#include "dealer.h"

Dealer::Dealer(){
}

int Dealer::buyPrice(Car car) {

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
    price -= car.getMileage() / 2;
    return price;
}

int Dealer::sellPrice(Car car) {

    int price;
    price = buyPrice(car);
    price += price / 5;

    return price;
}

void Dealer::buy(const Car& car, std::vector<Car> &garage) {

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

void Dealer::sell(const Car& car, const std::string& new_owner, std::vector<Car> &garage) {

    for(int i = 0; i < this -> parking.size(); i++) {
        if(car == parking.at(i)) {
            parking.at(i).owner = new_owner;
            std::cout << "Kupiłeś samochód: " << std::endl << parking.at(i) << std::endl << "za " << sellPrice(parking.at(i)) << " zł" << std::endl;
            garage.push_back(parking.at(i));
            parking.erase(parking.begin() + i);
        }
    }
}




