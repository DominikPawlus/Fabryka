#include <iostream>
#include <string>
#include <vector>

#include "factory.h"
#include "car.h"

using namespace std;

int main() {

    Factory BMW;
    vector<Car> sold_cars;

    cout << "Wybierz opcję: " << endl; 
    cout << "(1) - Wyprodukuj samochód" << endl << "(2) - Sprzedaj samochód z fabryki" << endl << "(3) - Jedź wybranym samochodem" << endl;

    int W;
    cin >> W;

    switch(W) {
        case 1: {
        
            string color;
            cout << "Podaj kolor: " << endl;
            cin >> color;

            int door_count;
            cout << "Podaj liczbę drzwi: " << endl;
            cin >> door_count;

            BMW.addNewCar(color, door_count);

            cout << "Wyprodukowany samochód: " << endl;
            BMW.printNew();
            break;
        }

        case 2: {
            
            cout << "Wybierz samochód, który chcesz sprzedać." << endl;

            string owner = "BMW";

            string color;
            cout << "Podaj kolor: " << endl;
            cin >> color;

            string brand;
            cout << "Podaj markę: " << endl;
            cin >> brand;

            int door_count;
            cout << "Podaj liczbę drzwi: " << endl;
            cin >> door_count;

            Car tmp = Car(owner, color, brand, door_count, 0);

            cout << "Podaj nazwisko nowego właściciela: " << endl;
            cin >> owner;

            Car* sold_car = BMW.sell(tmp, owner);
            if(sold_car == nullptr) {
                cout << "Podany samochód nie istnieje." << endl;
                break;
            }
            sold_cars.emplace_back(sold_car);
            cout << "Sprzedany samochód: " << sold_car << endl;
            break;
        }

        case 3: {

            cout << "Wybierz samochód, którym chcesz jechać." << endl;

            string owner;
            cout << "Podaj właściciela: " << endl; 
            cin >> owner;

            string color;
            cout << "Podaj kolor: " << endl;
            cin >> color;

            string brand;
            cout << "Podaj markę: " << endl;
            cin >> brand;

            int door_count;
            cout << "Podaj liczbę drzwi: " << endl;
            cin >> door_count;

            Car tmp = Car(owner, color, brand, door_count, 0);

            int dist;
            cout << "Podaj przejechany dystans: " << endl;
            cin >> dist;

            //Car::go(dist);
            break;
        }
    }
}