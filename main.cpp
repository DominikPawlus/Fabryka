#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "factory.h"
#include "Vehicles/car.h"
#include "procedures.h"
#include "dealer.h"
#include "varnisher.h"

using namespace std;

int main(int argc, char* argv[]) {

    ifstream plik;

    if(argc == 2) {
        plik.open(argv[1]);
        if(plik.is_open()) {
            cout << "Pomyślnie otwarto plik " << argv[1] << endl;
        }
    }


    Factory Fabryka = Factory("Gigafactory");
    vector<Car> sold_cars;
    Dealer Komis = Dealer();
    int W = 0;
    do {
        if(plik.is_open()) {
            cout << endl << "============================" << endl;
        } else {
            cout << "Wybierz opcję: " << endl;
            cout << "(1) - Wyprodukuj samochód" << endl << "(2) - Sprzedaj samochód z fabryki" << endl
                 << "(3) - Jedź wybranym samochodem" << endl
                 << "(4) - Wyświetl dane wybranego sprzedanego samochodu" << endl
                 << "(5) - Pokaż wzystkie sprzedane samochody" << endl << "(6) - Wizyta w komisie" << endl
                 << "(7) - wizyta u lakiernika" << endl << "(0) - Zamknij program" << endl;
        }
        if(plik.is_open()) {
            plik >> W;
        } else {
            cin >> W;
        }

        switch(W) {
            case 1: {

                cout << "FABRYKA" << endl << endl;

                string owner = "Gigafactory";
                int brand;
                string color;
                int door_count;

                if(plik.is_open()) {
                    plik >> brand;
                    plik >> color;
                    plik >> door_count;
                } else {
                    cout << "Wybierz markę samochodu: " << endl << "(1) - Audi" << endl << "(2) - Mercedes" << endl << "(3) - BMW" << endl;
                    cin >> brand;
                    cout << "Podaj kolor: " << std::endl;
                    cin >> color;
                    cout << "Podaj liczbę drzwi: " << std::endl;
                    cin >> door_count;
                }

                Fabryka.addNewCar(color, door_count, brand);

                cout << "Wyprodukowany samochód: " << endl;
                Fabryka.printNew();
                cout << endl;
                break;
            }

            case 2: {

                cout << "FABRYKA - SALON" << endl << endl;
                string owner;

                Car tmp;
                if(plik.is_open()) {
                    tmp = loadCarDataFile(W, 0, plik);
                    plik >> owner;
                } else {
                    cout << "Wybierz samochód, który chcesz sprzedać." << endl;
                    tmp = loadCarData(W, 0);
                    cout << "Podaj nazwisko nowego właściciela: " << endl;
                    cin >> owner;
                }

                Car* sold_car = Fabryka.sell(tmp, owner);
                if(sold_car == nullptr) {
                    cout << "Podany samochód nie istnieje." << endl;
                    break;
                } else {
                    cout << "Sprzedano samochód." << endl;
                }
                cout << *sold_car << endl << endl;
                sold_cars.push_back(*sold_car);
                break;
            }

            case 3: {

                cout << "DROGA" << endl << endl;

                Car tmp;
                if(plik.is_open()) {
                    tmp = loadCarDataFile(W, 0, plik);
                } else {
                    cout << "Wybierz samochód, którym chcesz jechać." << endl;
                    tmp = loadCarData(W, 0);
                }

                for(int i = 0; i < sold_cars.size(); i++) {
                    if(sold_cars.at(i) == tmp) {
                        tmp = sold_cars.at(i);
                        break;
                        } else {
                        cout << "Podany samochód nie istnieje." << endl;
                        break;
                    }
                }

                int dist;

                if(plik.is_open()) {
                    plik >> dist;
                } else {
                    cout << "Podaj przejechany dystans: " << endl;
                    cin >> dist;
                }

                tmp.go(dist, sold_cars);
                break;
            }
            case 4: {

                cout << "GARAŻ" << endl << endl;

                Car tmp;
                if(plik.is_open()) {
                    tmp = loadCarDataFile(W, 0, plik);
                } else {
                    tmp = loadCarData(W, 0);
                }

                for(int i = 0; i < sold_cars.size(); i++) {
                    if(sold_cars.at(i) == tmp) {
                        cout << "Dane wybranego samochodu: " << endl;
                        cout << sold_cars.at(i) << endl;
                    } else {
                        cout << "Podany samochód nie istnieje." << endl;
                        break;
                    }
                }
                break;
            }

            case 5: {

                cout << "LISTA" << endl << endl;
                cout << endl << "Samochody dostarczone do klientów: " << endl;
                for(int i = 0; i < sold_cars.size(); i++) {
                    cout << i + 1 << ". " << endl << sold_cars.at(i) << endl;
                }
                break;
            }

            case 6: {

                cout << "KOMIS" << endl << endl;

                int K = 0;

                if(plik.is_open()) {
                    plik >> K;
                } else {
                    cout << "(1) - Sprzedaj samochód" << endl << "(2) - Kup samochód z komisu" << endl;
                    cin >> K;
                }

                switch(K) {

                    case 1: {

                        Car tmp;
                        if(plik.is_open()) {
                            tmp = loadCarDataFile(W, K, plik);
                        } else {
                            tmp = loadCarData(W, K);
                        }

                        for (int i = 0; i < sold_cars.size(); i++) {
                            if (tmp == sold_cars.at(i)) {
                                Komis.buy(sold_cars.at(i), sold_cars);
                            }
                        }
                        break;
                    }

                    case 2: {
                        string new_owner;
                        Car tmp;

                        if(plik.is_open()) {
                            plik >> new_owner;
                            tmp = loadCarDataFile(W, K, plik);
                        } else {
                            cout << "Podaj nazwisko nowego właściciela: " << endl;
                            cin >> new_owner;
                            tmp = loadCarData(W, K);
                        }

                        Komis.sell(tmp, new_owner, sold_cars);
                        break;
                    }

                    default : {
                        break;
                    }
                }
                break;
            }

            case 7: {

                cout << "LAKIERNIK" << endl << endl;
                Car tmp;
                if(plik.is_open()) {
                    tmp = loadCarDataFile(W, 0, plik);
                } else {
                    tmp = loadCarData(W, 0);
                }

                for(int i = 0; i < sold_cars.size(); i++) {
                    if (sold_cars.at(i) == tmp) {
                        Varnisher::changeColor(sold_cars.at(i), plik);
                    } else {
                        if(i == sold_cars.size() - 1) {
                            cout << "Podany samochód nie istnieje." << endl;
                        }
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