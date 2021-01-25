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

                cout << "FABRYKA - linia produkcyjna" << endl;

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

                    Car tmp;
                    try {
                        tmp = loadCarData(W, plik);
                    }
                    catch(false_brand &kapsula) {
                        if(plik.is_open()) {
                            cout << kapsula.msg << endl << "Podaj poprawny plik." << endl;
                            exit(EXIT_FAILURE);
                        } else {
                            cout << kapsula.msg << endl;
                            break;
                        }
                    }
                    catch(false_door_count &kapsula) {
                        if(plik.is_open()) {
                            cout << kapsula.msg << endl << "Podaj poprawny plik." << endl;
                            exit(EXIT_FAILURE);
                        } else {
                            cout << kapsula.msg << endl;
                            break;
                        }
                    }

                    if (tmp.getBrand() == "BMW") {
                        BMW.addNew(tmp.color, tmp.getDoorCount());
                    }
                    if (tmp.getBrand() == "Audi") {
                        Audi.addNew(tmp.color, tmp.getDoorCount());
                    }
                    if (tmp.getBrand() == "Mercedes") {
                        Mercedes.addNew(tmp.color, tmp.getDoorCount());
                    }

                    cout << "Wyprodukowano samochód." << endl;
                    break;
                }

                case (2): {

                    Motorcycle tmp;
                    tmp = loadMotorData(W, plik);

                    if (tmp.getBrand() == "Kawasaki") {
                        Kawasaki.addNew(tmp.color);
                    }
                    if (tmp.getBrand() == "Honda") {
                        Honda.addNew(tmp.color);
                    }

                    cout << "Wyprodukowano motocykl." << endl;
                    break;
                }

                case (3): {

                    Bike tmp;
                    tmp = loadBikeData(W, plik);
                    Romet.addNew(tmp.color, tmp.isBasket(), tmp.getGears());

                    cout << "Wyprodukowano rower." << endl;
                    break;
                }

                default: {
                    break;
                }
            }

                break;
            }

            case 2: {

                cout << "FABRYKA - salon sprzedaży" << endl;

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

                        Car tmp;
                        string new_owner;

                        tmp = loadCarData(W, plik);

                        try {
                            if (tmp.getBrand() == "BMW") {
                                cars.push_back(*BMW.sell(tmp));
                            }

                            if (tmp.getBrand() == "Audi") {
                                cars.push_back(*Audi.sell(tmp));
                            }
                            if (tmp.getBrand() == "Mercedes") {
                                cars.push_back(*Mercedes.sell(tmp));
                            }
                        }
                        catch(vehicle_no_exist &kapsula) {
                            if(plik.is_open()) {
                                cout << kapsula.msg << endl << "Podaj poprawny plik." << endl;
                                exit(EXIT_FAILURE);
                            } else {
                                cout << kapsula.msg << endl;
                                break;
                            }
                        }

                        if (plik.is_open()) {
                            plik >> new_owner;
                        } else {
                            cout << "Podaj nazwisko nowego właściciela: " << endl;
                            cin >> new_owner;
                        }

                        cars.at(cars.size() - 1).owner = new_owner;

                        cout << "Sprzedano samochód." << endl;
                        break;
                    }

                    case (2): {

                        Motorcycle tmp;
                        string new_owner;

                        tmp = loadMotorData(W, plik);

                        if (tmp.getBrand() == "Kawasaki") {
                            motorcycles.push_back(*Kawasaki.sell(tmp));
                        }
                        if (tmp.getBrand() == "Honda") {
                            motorcycles.push_back(*Honda.sell(tmp));
                        }

                        if (plik.is_open()) {
                            plik >> new_owner;
                        } else {
                            cout << "Podaj nazwisko nowego właściciela: " << endl;
                            cin >> new_owner;
                        }

                        motorcycles.at(motorcycles.size() - 1).owner = new_owner;

                        cout << "Sprzedano motocykl." << endl;
                        break;
                    }

                    case (3): {

                        Bike tmp;
                        string new_owner;

                        tmp = loadBikeData(W, plik);
                        bikes.push_back(*Romet.sell(tmp));

                        if (plik.is_open()) {
                            plik >> new_owner;
                        } else {
                            cout << "Podaj nazwisko nowego właściciela: " << endl;
                            cin >> new_owner;
                        }

                        bikes.at(bikes.size() - 1).owner = new_owner;

                        cout << "Sprzedano rower." << endl;

                        break;
                    }

                    default: {
                        break;
                    }
                }
                break;
            }
            case 3: {

                cout << "STAROSTWO - rejestracja pojazdu" << endl;

                int K;
                if (plik.is_open()) {
                    plik >> K;
                } else {
                    cout << "Wybierz rodzaj pojazdu: " << endl;
                    cout << "(1) - samochód" << endl << "(2) - motocykl" << endl;
                    cin >> K;
                }

                switch (K) {

                    case (1): {
                        int n = findVehicle<Car>(loadCarData(W, plik), cars);
                        Office::registerVehicle(cars.at(n), plik);
                        break;
                    }
                    case (2): {
                        int n = findVehicle<Motorcycle>(loadMotorData(W, plik), motorcycles);
                        Office::registerVehicle(motorcycles.at(n), plik);
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }

            case 4: {

                cout << "DROGA" << endl;

                string number;
                float km;
                int K;

                if (plik.is_open()) {
                    plik >> K >> km;
                } else {
                    cout << "Wybierz rodzaj pojazdu: " << endl;
                    cout << "(1) - samochód" << endl << "(2) - motocykl" << endl << "(3) - rower" << endl;
                    cin >> K;
                    cout << "Podaj liczbę kilometrów: " << endl;
                    cin >> km;
                }

                switch (K) {

                    case (1): {

                        if (plik.is_open()) {
                            plik >> number;
                        } else {
                            cout << "Podaj numer tablicy rejestracyjnej samochodu: " << endl;
                            cin >> number;
                        }

                        int n;
                        try {
                            n = findNumber<Car>(cars, number);
                        }
                        catch(vehicle_no_exist &kapsula) {
                            if(plik.is_open()) {
                                cout << kapsula.msg << endl << "Podaj poprawny plik." << endl;
                                exit(EXIT_FAILURE);
                            } else {
                                cout << kapsula.msg << endl;
                                break;
                            }
                        }

                        cars.at(n).go(km);

                        break;
                    }

                    case (2): {

                        if (plik.is_open()) {
                            plik >> number;
                        } else {
                            cout << "Podaj numer tablicy rejestracyjnej motocykla: " << endl;
                            cin >> number;
                        }

                        int n = findNumber<Motorcycle>(motorcycles, number);
                        motorcycles.at(n).go(km);

                        break;
                    }

                    case (3): {

                        Bike tmp = loadBikeData(W, plik);
                        int n = findVehicle<Bike>(tmp, bikes);
                        bikes.at(n).go(km);

                        break;
                    }

                    default: {

                        break;
                    }
                }
                break;
            }

            case 5: {

                cout << "LISTA" << endl << endl;
                cout << "Samochody: " << endl << endl;

                for (int i = 0; i < cars.size(); i++) {
                    cout << i + 1 << ". " << endl << cars.at(i) << endl;
                }

                cout << "Motocykle: " << endl << endl;

                for (int i = 0; i < motorcycles.size(); i++) {
                    cout << i + 1 << ". " << endl << motorcycles.at(i) << endl;
                }

                cout << "Rowery: " << endl << endl;

                for (int i = 0; i < bikes.size(); i++) {
                    cout << i + 1 << ". " << endl << bikes.at(i) << endl;
                }

                break;
            }

            case 6: {
                cout << "KOMIS" << endl;

                string number;
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

                        int J;

                        if (plik.is_open()) {
                            plik >> J;
                        } else {
                            cout << "(1) - kup samochód" << endl << "(2) - sprzedaj samochód " << endl;
                            cin >> J;
                        }

                        if(J == 1) {

                            cout << "Samochody dostępne w komisie: " << endl;

                            if(Autokomis.getParkSize() == 0) {
                                cout << "W komisie nie ma żadnych dostępnych samochodów." << endl;
                                break;
                            } else {
                                for (int i = 0; i < Autokomis.getParkSize(); i++) {
                                    cout << i + 1 << ". " << endl << Autokomis.showParking().at(i) << endl;
                                }
                            }

                            string new_owner;
                            if (plik.is_open()) {
                                plik >> number >> new_owner;
                            } else {
                                cout << "Podaj numer tablicy rejestracyjnej samochodu: " << endl;
                                cin >> number;
                                cout << "Podaj nazwisko nowego właściciela: " << endl;
                                cin >> new_owner;
                            }

                            vector<Car> parking = Autokomis.showParking();
                            int n = findNumber<Car>(parking, number);

                            Autokomis.sell(Autokomis.showParking().at(n), new_owner, cars);
                        }

                        if(J == 2) {

                            if (plik.is_open()) {
                                plik >> number;
                            } else {
                                cout << "Podaj numer tablicy rejestracyjnej samochodu: " << endl;
                                cin >> number;
                            }

                            int n = findNumber<Car>(cars, number);

                            Autokomis.buy(cars.at(n), cars);
                        }

                        break;
                    }

                   case (2): {

                       int J;
                       if (plik.is_open()) {
                           plik >> J;
                       } else {
                           cout << "(1) - kup motocykl" << endl << "(2) - sprzedaj motocykl " << endl;
                           cin >> J;
                       }

                       if(J == 1) {

                           cout << "Motocykle dostępne w komisie: " << endl;

                           if(Motorkomis.getParkSize() == 0) {
                               cout << "W komisie nie ma żadnych dostępnych motocykli." << endl;
                               break;
                           } else {
                               for (int i = 0; i < Motorkomis.getParkSize(); i++) {
                                   cout << i + 1 << ". " << endl << Motorkomis.showParking().at(i) << endl;
                               }
                           }

                           string new_owner;
                           if (plik.is_open()) {
                               plik >> number >> new_owner;
                           } else {
                               cout << "Podaj numer tablicy rejestracyjnej motocykla: " << endl;
                               cin >> number;
                               cout << "Podaj nazwisko nowego właściciela: " << endl;
                               cin >> new_owner;
                           }

                           vector<Motorcycle> parking = Motorkomis.showParking();
                           int n = findNumber<Motorcycle>(parking, number);

                           Motorkomis.sell(Motorkomis.showParking().at(n), new_owner, motorcycles);
                       }

                       if(J == 2) {

                           if (plik.is_open()) {
                               plik >> number;
                           } else {
                               cout << "Podaj numer tablicy rejestracyjnej motocykla: " << endl;
                               cin >> number;
                           }

                           int n = findNumber<Motorcycle>(motorcycles, number);

                           Motorkomis.buy(motorcycles.at(n), motorcycles);
                       }
                        break;
                   }

                   case (3): {

                       int J;
                       if (plik.is_open()) {
                           plik >> J;
                       } else {
                           cout << "(1) - kup rower" << endl << "(2) - sprzedaj rower " << endl;
                           cin >> J;
                       }

                       if(J == 1) {

                           cout << "Rowery dostępne w komisie: " << endl;

                           if(Bajkomis.getParkSize() == 0) {
                               cout << "W komisie nie ma żadnych dostępnych rowerów." << endl;
                               break;
                           } else {
                               for (int i = 0; i < Bajkomis.getParkSize(); i++) {
                                   cout << i + 1 << ". " << endl << Bajkomis.showParking().at(i) << endl;
                               }
                           }

                           Bike tmp = loadBikeData(W, plik);
                           vector<Bike> parking = Bajkomis.showParking();
                           int n = findVehicle<Bike>(tmp, parking);

                           string new_owner;
                           if (plik.is_open()) {
                               plik >> new_owner;
                           } else {
                               cout << "Podaj nazwisko nowego właściciela: " << endl;
                               cin >> new_owner;
                           }


                           Bajkomis.sell(Bajkomis.showParking().at(n), new_owner, bikes);
                       }

                       if(J == 2) {

                           Bike tmp = loadBikeData(W, plik);
                           vector<Bike> parking = Bajkomis.showParking();
                           int n = findVehicle<Bike>(tmp, bikes);

                           Bajkomis.buy(bikes.at(n), bikes);
                       }

                        break;
                   }

                        default: {

                            break;
                        }
                }

                break;
            }

            case 7: {

                cout << "LAKIERNIK" << endl;

                string number;
                int K;

                if (plik.is_open()) {
                    plik >> K;
                } else {
                    cout << "Wybierz rodzaj pojazdu: " << endl;
                    cout << "(1) - samochód" << endl << "(2) - motocykl" << endl;
                    cin >> K;
                }

                switch (K) {

                    case (1): {

                        if (plik.is_open()) {
                            plik >> number;
                        } else {
                            cout << "Podaj numer tablicy rejestracyjnej samochodu: " << endl;
                            cin >> number;
                        }

                        int n = findNumber<Car>(cars, number);
                        Varnisher<Car>::changeColor(cars.at(n), plik);

                        break;
                    }

                    case (2): {

                        if (plik.is_open()) {
                            plik >> number;
                        } else {
                            cout << "Podaj numer tablicy rejestracyjnej motocykla: " << endl;
                            cin >> number;
                        }

                        int n = findNumber<Motorcycle>(motorcycles, number);
                        Varnisher<Motorcycle>::changeColor(motorcycles.at(n), plik);

                        break;
                    }
                    default: {
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

    cars.clear();
    motorcycles.clear();
    bikes.clear();

    return 0;
}