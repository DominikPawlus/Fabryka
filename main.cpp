#include <iostream>
#include <string>
#include <vector>

#include "factory.h"
#include "Vehicles/car.h"
#include "procedures.h"
#include "dealer.h"
#include "varnisher.h"

using namespace std;

int main() {

    Factory Fabryka = Factory("Gigafactory");
    vector<Car> sold_cars;
    Dealer Komis = Dealer();
    int W = 0;
    do {
        cout << "Wybierz opcję: " << endl; 
        cout << "(1) - Wyprodukuj samochód" << endl << "(2) - Sprzedaj samochód z fabryki" << endl << "(3) - Jedź wybranym samochodem" << endl
        << "(4) - Wyświetl dane wybranego sprzedanego samochodu" << endl << "(5) - Pokaż wzystkie sprzedane samochody" << endl << "(6) - Wizyta w komisie" << endl << "(0) - Zamknij program" << endl;
        cin >> W;
        switch(W) {
            case 1: {

                string owner = "Gigafactory";
                int brand;
                cout << "Wybierz markę samochodu: " << endl << "(1) - Audi" << endl << "(2) - Mercedes" << endl << "(3) - BMW" << endl;
                cin >> brand;

                string color;
                cout << "Podaj kolor: " << std::endl;
                cin >> color;

                int door_count;
                cout << "Podaj liczbę drzwi: " << std::endl;
                cin >> door_count;

                Fabryka.addNewCar(color, door_count, brand);

                cout << "Wyprodukowany samochód: " << endl;
                Fabryka.printNew();
                break;
            }

            case 2: {
                
                cout << "Wybierz samochód, który chcesz sprzedać." << endl;

                string owner;

                Car tmp = loadCarData(W, 0);
                cout << "Podaj nazwisko nowego właściciela: " << endl;
                cin >> owner;

                Car* sold_car = Fabryka.sell(tmp, owner);
                if(sold_car == nullptr) {
                    cout << "Podany samochód nie istnieje." << endl;
                    break;
                } else {
                    cout << "Sprzedano samochód." << endl;
                }
                cout << *sold_car << endl;
                sold_cars.push_back(*sold_car);
                break;
            }

            case 3: {

                cout << "Wybierz samochód, którym chcesz jechać." << endl;

                Car tmp = loadCarData(W, 0);

                for(int i = 0; i < sold_cars.size(); i++) {
                    if(sold_cars.at(i) == tmp) {
                        break;
                        } else {
                        cout << "Podany samochód nie istnieje." << endl;
                        break;
                    }
                }

                int dist;
                cout << "Podaj przejechany dystans: " << endl;
                cin >> dist;

                tmp.go(dist, sold_cars);
                break;
            }
            case 4: {

                Car tmp = loadCarData(W, 0);

                for(int i = 0; i < sold_cars.size(); i++) {
                    if(sold_cars.at(i) == tmp) {
                        cout << sold_cars.at(i) << endl;
                    } else {
                        cout << "Podany samochód nie istnieje." << endl;
                        break;
                    }
                }
                break;
            }

            case 5: {
                for(int i = 0; i < sold_cars.size(); i++) {
                    cout << i + 1 << ". " << endl << sold_cars.at(i) << endl;
                }
                break;
            }

            case 6: {

                cout << "(1) - Sprzedaj samochód" << endl << "(2) - Kup samochód z komisu" << endl;
                int K = 0;
                cin >> K;
                switch(K) {

                    case 1: {

                        Car tmp = loadCarData(W, K);

                        for (int i = 0; i < sold_cars.size(); i++) {
                            if (tmp == sold_cars.at(i)) {
                                Komis.buy(sold_cars.at(i), sold_cars);
                            }
                        }
                        break;
                    }

                    case 2: {
                        string owner;
                        cout << "Podaj nazwisko nowego właściciela: " << endl;
                        cin >> owner;

                        Car tmp = loadCarData(W, K);
                        Komis.sell(tmp, owner, sold_cars);
                        break;
                    }

                    default : {
                        break;
                    }
                }
                break;
            }

            case 7: {

                Car tmp = loadCarData(W, 0);
                for(int i = 0; i < sold_cars.size(); i++) {
                    if (sold_cars.at(i) == tmp) {
                        Varnisher::changeColor(sold_cars.at(i));
                    } else {
                        cout << "Podany samochód nie istnieje." << endl;
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