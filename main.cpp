#include <iostream>
#include <string>
#include <vector>

#include "factory.h"
#include "car.h"

using namespace std;

int main() {

    Factory BMW;

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
            break;
        }

        case 2: {
            //BMW.sell();
            break;
        }

        case 3: {
            //Car::go();
            break;
        }
    }
}