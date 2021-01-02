#include <iostream>
#include <string>
#include <vector>

#include "factory.h"
#include "Vehicles/car.h"

using namespace std;

int main() {

    Factory Fabryka = Factory("Gigafactory");
    vector<Car> sold_cars;
    int W;
    do {
        cout << "Wybierz opcję: " << endl; 
        cout << "(1) - Wyprodukuj samochód" << endl << "(2) - Sprzedaj samochód z fabryki" << endl << "(3) - Jedź wybranym samochodem" << endl
        << "(4) - Wyświetl dane wybranego sprzedanego samochodu" << endl << "(5) - Pokaż wzystkie sprzedane samochody" << endl << "(0) - Zamknij program" << endl;
        cin >> W;
        switch(W) {
            case 1: {

                int brand;
                std::cout << "Wybierz markę samochodu: " << std::endl << "(1) - Audi" << std::endl << "(2) - Mercedes" << std::endl << "(3) - BMW" << std::endl;
                cin >> brand;

                string color;
                cout << "Podaj kolor: " << endl;
                cin >> color;

                int door_count;
                cout << "Podaj liczbę drzwi: " << endl;
                cin >> door_count;

                Fabryka.addNewCar(color, door_count, brand);

                cout << "Wyprodukowany samochód: " << endl;
                Fabryka.printNew();
                break;
            }

            case 2: {
                
                cout << "Wybierz samochód, który chcesz sprzedać." << endl;

                string owner = "Gigafactory";

                string brand;
                cout << "Podaj markę: " << endl;
                cin >> brand;

                string color;
                cout << "Podaj kolor: " << endl;
                cin >> color;


                int door_count;
                cout << "Podaj liczbę drzwi: " << endl;
                cin >> door_count;

                Car tmp = Car(owner, color, brand, door_count, 0, 0); //capacity = 0, fuel_amount = 0 nie ma znaczenia dla tmp

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

                string owner;
                cout << "Podaj właściciela: " << endl; 
                cin >> owner;

                string brand;
                cout << "Podaj markę: " << endl;
                cin >> brand;

                string color;
                cout << "Podaj kolor: " << endl;
                cin >> color;

                int door_count;
                cout << "Podaj liczbę drzwi: " << endl;
                cin >> door_count;

                Car tmp = Car(owner, color, brand, door_count, 0, 0); //capacity = 0, fuel_amount = 0 nie ma znaczenia dla tmp

                for(int i = 0; i < sold_cars.size(); i++) {
                    if(sold_cars.at(i) == tmp) {
                        break;
                        } else {
                        cout << "Podany samochód nie istnieje." << endl;
                    }
                }

                int dist;
                cout << "Podaj przejechany dystans: " << endl;
                cin >> dist;

                tmp.go(dist, sold_cars);
                break;
            }
            case 4: {
                string owner;
                cout << "Podaj właściciela: " << endl;
                cin >> owner;

                string brand;
                cout << "Podaj markę: " << endl;
                cin >> brand;

                string color;
                cout << "Podaj kolor: " << endl;
                cin >> color;

                int door_count;
                cout << "Podaj liczbę drzwi: " << endl;
                cin >> door_count;

                Car tmp = Car(owner, color, brand, door_count, 0, 0); //capacity = 0, fuel_amount = 0 nie ma znaczenia dla tmp

                for(int i = 0; i < sold_cars.size(); i++) {
                    if(sold_cars.at(i) == tmp) {
                        cout << sold_cars.at(i) << endl;
                    } else {
                        cout << "Podany samochód nie istnieje." << endl;
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

            default: {
                break;
            }
        }
    } while(W != 0);
    return 0;
}