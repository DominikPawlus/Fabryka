#include <iostream>
#include <string>
#include <vector>

#include "Factory/factory.h"
#include "Factory/c_factory.h"
#include "Factory/m_factory.h"
#include "Factory/b_factory.h"
#include "Vehicles/car.h"
#include "Vehicles/motorcycle.h"
#include "Vehicles/bike.h"
#include "procedures.h"
#include "Services/dealer.h"
#include "Services/varnisher.h"
#include "Services/office.h"

using namespace std;

int main(int argc, char* argv[]) {

    ifstream plik;

    if(argc == 2) {
        plik.open(argv[1]);
        if(plik.is_open()) {
            cout << "Pomyślnie otwarto plik " << argv[1] << "." << endl;
        }
    }

    CarFactory<Car> BMW = CarFactory<Car>("BMW", 500, 90, 11.5);
    CarFactory<Car> Audi = CarFactory<Car>("Audi", 400, 80, 8.2);
    CarFactory<Car> Mercedes = CarFactory<Car>("Mercedes", 600, 60, 10.4);

    MotorFactory<Motorcycle> Kawasaki = MotorFactory<Motorcycle>("Kawasaki", 20, 15, 1.8);
    MotorFactory<Motorcycle> Honda = MotorFactory<Motorcycle>("Honda", 30, 12, 1.6);

    BikeFactory<Bike> Romet = BikeFactory<Bike>("Romet", 5, 0, 0);

    Dealer<Car> Autokomis = Dealer<Car>();
    Dealer<Motorcycle> Motorkomis = Dealer<Motorcycle>();
    Dealer<Bike> Bajkomis = Dealer<Bike>();

    vector<Car> cars;
    vector<Motorcycle> motorcycles;
    vector<Bike> bikes;

    int W = 0;

    do {

        if(plik.is_open()) {
            cout << endl << "============================" << endl;
        } else {
            cout << "Wybierz opcję: " << endl;
            cout << "(1) - Wyprodukuj pojazd" << endl << "(2) - Sprzedaj pojazd z fabryki" << endl
                 << "(3) - Zarejestruj pojazd" << endl
                 << "(4) - Jedź wybranym pojazdem" << endl
                 << "(5) - Pokaż wzystkie sprzedane pojazdy" << endl << "(6) - Wizyta w komisie" << endl
                 << "(7) - Wizyta u lakiernika" << endl << "(0) - Zamknij program" << endl;
        }

        if(plik.is_open()) {
            plik >> W;
        } else {
            cin >> W;
        }

        switch(W) {
            case 1: {

                cout << "FABRYKA - linia produkcyjna" << endl << endl;

                int K;
                if (plik.is_open()) {
                    plik >> K;
                } else {
                    cout << "Wybierz rodzaj pojazdu: " << endl;
                    cout << "(1) - samochód" << endl << "(2) - motocykl" << endl << "(3) - rower" << endl;
                    cin >> K;
            }

            switch (K) {

                case (1): {

                    Car *tmp;
                    tmp = loadCarData(W, plik);

                    cout << tmp->getDoorCount() << endl;
                    cout << "Marka: " << tmp->getBrand() << endl;

                    if (tmp->getBrand() == "BMW") {
                        cout << "w ifie: " << tmp->getDoorCount() << endl;
                        BMW.addNew(tmp->color, tmp->getDoorCount());
                    }
                    if (tmp->getBrand() == "Audi") {
                        Audi.addNew(tmp->color, tmp->getDoorCount());
                    }
                    if (tmp->getBrand() == "Mercedes") {
                        Mercedes.addNew(tmp->color, tmp->getDoorCount());
                    }

                    break;
                }

                case (2): {

                    Motorcycle *tmp;
                    tmp = loadMotorData(W, plik);

                    if (tmp->getBrand() == "Kawasaki") {
                        Kawasaki.addNew(tmp->color);
                    }
                    if (tmp->getBrand() == "Honda") {
                        Honda.addNew(tmp->color);
                    }

                    break;
                }

                case (3): {

                    Bike *tmp;
                    tmp = loadBikeData(W, plik);
                    Romet.addNew(tmp->color, tmp->isBasket());

                    break;
                }

                default: {
                    break;
                }
            }

                break;
            }

            case 2: {

                cout << "FABRYKA - salon sprzedaży" << endl << endl;

                int K;
                if (plik.is_open()) {
                    plik >> K;
                } else {
                    cout << "Wybierz rodzaj pojazdu: " << endl;
                    cout << "(1) - samochód" << endl << "(2) - motocykl" << endl << "(3) - rower" << endl;
                    cin >> K;
                }

                switch (K) {

                    case (1): {

                        Car *tmp;
                        string new_owner;

                        tmp = loadCarData(W, plik);
                        cout << tmp->getBrand() << endl;

                        //if (tmp->getBrand() == "BMW") {
                            cars.push_back(*BMW.sell(tmp));
                            cout << cars.size() << endl;
                        //}

                        if (tmp->getBrand() == "Audi") {
                            cars.push_back(*Audi.sell(tmp));
                        }
                        if (tmp->getBrand() == "Mercedes") {
                            cars.push_back(*Mercedes.sell(tmp));
                        }

                        if (plik.is_open()) {
                            plik >> new_owner;
                        } else {
                            cout << "Podaj nazwisko nowego właściciela: " << endl;
                            cin >> new_owner;
                        }

                        cars.end() -> owner = new_owner;

                        cout << "Sprzedano samochód." << endl;

                        break;
                    }

                    case (2): {

                        Motorcycle *tmp;
                        string new_owner;

                        tmp = loadMotorData(W, plik);

                        if (tmp->getBrand() == "Kawasaki") {
                            motorcycles.push_back(*Kawasaki.sell(*tmp));
                        }
                        if (tmp->getBrand() == "Honda") {
                            motorcycles.push_back(*Honda.sell(*tmp));
                        }

                        if (plik.is_open()) {
                            plik >> new_owner;
                        } else {
                            cout << "Podaj nazwisko nowego właściciela: " << endl;
                            cin >> new_owner;
                        }

                        motorcycles.end()->owner = new_owner;

                        cout << "Sprzedano motocykl." << endl;

                        break;
                    }

                    case (3): {

                        Bike *tmp;
                        string new_owner;

                        tmp = loadBikeData(W, plik);
                        bikes.push_back(*Romet.sell(*tmp));

                        if (plik.is_open()) {
                            plik >> new_owner;
                        } else {
                            cout << "Podaj nazwisko nowego właściciela: " << endl;
                            cin >> new_owner;
                        }

                        bikes.end()->owner = new_owner;

                        cout << "Sprzedano rower." << endl;

                        break;
                    }

                    default: {
                        break;
                    }
                        break;
                }
            }
            case 3: {

                cout << "STAROSTWO - rejestracja pojazdu" << endl;

                int K;
                if (plik.is_open()) {
                    plik >> K;
                } else {
                    cout << "Wybierz rodzaj pojazdu: " << endl;
                    cout << "(1) - samochód" << endl << "(2) - motocykl";
                    cin >> K;
                }

                switch (K) {

                    case (1): {
                        Car *tmp = loadCarData(W, plik);
                        int n = findVehicle<Car>(*tmp, cars);
                        Office::registerVehicle(cars.at(n), plik);
                        break;
                    }
                    case (2): {
                        int n = findVehicle<Motorcycle>(*loadMotorData(W, plik), motorcycles);
                        Office::registerVehicle(motorcycles.at(n), plik);
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }

            case 4: {

                cout << "DROGA" << endl;

                string number;
                float km;
                int K;

                if (plik.is_open()) {
                    plik >> number;
                } else {
                    cout << "Wybierz rodzaj pojazdu: " << endl;
                    cout << "(1) - samochód" << endl << "(2) - motocykl" << endl << "(3) - rower" << endl;
                    cin >> K;
                }

                switch (K) {

                    case (1): {
                        cout << "Podaj numer tablicy rejestracyjnej samochodu: " << endl;
                        cin >> number;

                        int n = findNumber<Car>(cars, number);
                        cars.at(n).go(km);

                        break;
                    }

                    case (2): {
                        cout << "Podaj numer tablicy rejestracyjnej motocykla: " << endl;
                        cin >> number;

                        int n = findNumber<Motorcycle>(motorcycles, number);
                        motorcycles.at(n).go(km);

                        break;
                    }

                    case (3): {

                        Bike *tmp = loadBikeData(W, plik);
                        int n = findVehicle<Bike>(*tmp, bikes);
                        bikes.at(n).go(km);

                        break;
                    }
                }

                break;
            }

            case 5: {

                cout << "LISTA" << endl << endl;
                cout << "Samochody: " << endl;

                for (auto &car : cars) {
                    cout << car << endl;
                }

                cout << "Motocykle: " << endl;

                for (auto &motorcycle : motorcycles) {
                    cout << motorcycle;
                }

                cout << "Rowery: " << endl;

                for (const auto &bike : bikes) {
                    cout << bike;
                }

                break;
            }

            case 6: {

                break;
            }

            case 7: {

                cout << "LAKIERNIK" << endl;

                string number;
                int K;

                if (plik.is_open()) {
                    plik >> number;
                } else {
                    cout << "Wybierz rodzaj pojazdu: " << endl;
                    cout << "(1) - samochód" << endl << "(2) - motocykl" << endl;
                    cin >> K;
                }

                switch (K) {

                    case (1): {

                        cout << "Podaj numer tablicy rejestracyjnej samochodu: " << endl;
                        cin >> number;

                        int n = findNumber<Car>(cars, number);
                        Varnisher<Car>::changeColor(cars.at(n), plik);

                        break;
                    }

                    case (2): {
                        cout << "Podaj numer tablicy rejestracyjnej motocykla: " << endl;
                        cin >> number;

                        int n = findNumber<Motorcycle>(motorcycles, number);
                        Varnisher<Motorcycle>::changeColor(motorcycles.at(n), plik);

                        break;
                    }
                }

                break;
            }

            default: {
                break;
            }
        }
    } while(W != 0);
    return 0;
}