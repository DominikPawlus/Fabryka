#include <iostream>
#include <string>
#include <vector>

#include "factory.h"
#include "Vehicles/engine_vehicle.h"
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

    Factory<Car> Fabryka = Factory<Car> ("Gigafactory");
    Dealer<Engine_Vehicle> Komis = Dealer<Engine_Vehicle>();

    vector<Engine_Vehicle> sold_engine_vehicles;

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
                 << "(7) - Wizyta u lakiernika" << endl << "(0) - Zamknij program" << endl;
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

                Fabryka.addNewVehicle(color, door_count, brand);

                cout << "Wyprodukowany pojazd: " << endl;
                Fabryka.printNew();
                cout << endl;
                break;
            }

            case 2: {

                cout << "FABRYKA - SALON" << endl << endl;
                string owner;

                Car tmp;

                if(plik.is_open()) {
                    try {
                        Car tmp = loadEngineVehicleDataFile<Car>(W, plik);
                    }
                    catch (false_door_count &kapsula) {
                        cout << kapsula.msg << endl << "Podaj poprawny plik." << endl;
                        exit (EXIT_FAILURE);
                    }
                    plik >> owner;

                } else {
                    cout << "Wybierz pojazd, który chcesz sprzedać." << endl;

                    try {
                        Car tmp = loadEngineVehicleData<Car>(W, 0);
                    }
                    catch (false_door_count &kapsula) {
                        cout << kapsula.msg << endl;
                    }

                    cout << "Podaj nazwisko nowego właściciela: " << endl;
                    cin >> owner;
                }

                Car *sold_car = Fabryka.sell(tmp, owner);
                if(sold_car == nullptr) {
                    cout << "Podany pojazd nie istnieje." << endl;
                    break;
                } else {
                    cout << "Sprzedano samochód." << endl;
                }
                cout << *sold_car << endl << endl;
                sold_engine_vehicles.push_back(*sold_car);
                break;
            }

            case 3: {

                cout << "DROGA" << endl << endl;

                Engine_Vehicle tmp;
                if(plik.is_open()) {
                    try {
                        Car tmp = loadEngineVehicleDataFile<Car>(W, plik);
                    }
                    catch(false_door_count &kapsula){
                        cout << kapsula.msg << endl << "Podaj poprawny plik." << endl;
                        exit (EXIT_FAILURE);
                    }
                } else {
                    cout << "Wybierz samochód, którym chcesz jechać." << endl;
                    Car tmp = loadEngineVehicleData<Car>(W, 0);
                }

                try {
                    tmp = sold_engine_vehicles.at(findEngineVehicle(tmp, sold_engine_vehicles));
                }
                catch(car_no_exist &kapsula) {
                    cout << kapsula.msg << endl;
                }

                float dist;

                if(plik.is_open()) {
                    plik >> dist;
                } else {
                    cout << "Podaj przejechany dystans: " << endl;
                    cin >> dist;
                }

                tmp.go(dist, sold_engine_vehicles);
                break;
            }
            case 4: {

                cout << "GARAŻ" << endl << endl;

                Engine_Vehicle tmp;
                if(plik.is_open()) {
                    try {
                        Car tmp = loadEngineVehicleDataFile<Car>(W, plik);
                    }
                    catch(false_door_count &kapsula){
                        cout << kapsula.msg << endl << "Podaj poprawny plik." << endl;
                        exit (EXIT_FAILURE);
                    }
                } else {
                    try {
                        Car tmp = loadEngineVehicleData<Car>(W, 0);
                    }
                    catch(false_door_count &kapsula){
                        cout << kapsula.msg << endl;
                    }
                }

                try {
                    tmp = sold_engine_vehicles.at(findEngineVehicle(tmp, sold_engine_vehicles));
                }
                catch(car_no_exist &kapsula) {
                    cout << kapsula.msg << endl;
                }

                cout << "Dane wybranego samochodu: " << endl << tmp << endl;

                break;
            }

            case 5: {

                cout << "LISTA" << endl << endl;
                cout << endl << "Samochody dostarczone do klientów: " << endl;
                for(int i = 0; i < sold_engine_vehicles.size(); i++) {
                    cout << i + 1 << ". " << endl << sold_engine_vehicles.at(i) << endl;
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

                        Engine_Vehicle tmp;
                        if(plik.is_open()) {
                            try {
                                Car tmp = loadEngineVehicleDataFile<Car>(W, plik);
                            }
                            catch(false_door_count &kapsula){
                                cout << kapsula.msg << endl << "Podaj poprawny plik." << endl;
                                exit (EXIT_FAILURE);
                            }
                        } else {
                            try {
                                Car tmp = loadEngineVehicleData<Car>(W, K);
                            }
                            catch(false_door_count &kapsula) {
                                cout << kapsula.msg << endl;
                            }
                        }

                        for (int i = 0; i < sold_engine_vehicles.size(); i++) {
                            if (tmp == sold_engine_vehicles.at(i)) {
                                Komis.buyCar(sold_engine_vehicles.at(i), sold_engine_vehicles);
                            }
                        }
                        break;
                    }

                    case 2: {
                        string new_owner;
                        Engine_Vehicle tmp;

                        if(plik.is_open()) {
                            plik >> new_owner;
                            try {
                                Car tmp = loadEngineVehicleDataFile<Car>(W, plik);
                            }
                            catch(false_door_count &kapsula){
                                cout << kapsula.msg << endl << "Podaj poprawny plik." << endl;
                                exit (EXIT_FAILURE);
                            }
                        } else {
                            cout << "Podaj nazwisko nowego właściciela: " << endl;
                            cin >> new_owner;
                            try {
                                Car tmp = loadEngineVehicleData<Car>(W, K);
                            }
                            catch(false_door_count &kapsula) {
                                cout << kapsula.msg << endl;
                            }
                        }

                        Komis.sellCar(tmp, new_owner, sold_engine_vehicles);
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
                Engine_Vehicle tmp;
                int tmp_i;
                if(plik.is_open()) {
                    try {
                        Car tmp = loadEngineVehicleDataFile<Car>(W, plik);
                    }
                    catch(false_door_count &kapsula){
                        cout << kapsula.msg << endl << "Podaj poprawny plik." << endl;
                        exit (EXIT_FAILURE);
                    }
                } else {
                    try {
                        Car tmp = loadEngineVehicleData<Car>(W, 0);
                    }
                    catch(false_door_count &kapsula) {
                        cout << kapsula.msg;
                    }
                }
                try {
                    tmp_i = findEngineVehicle(tmp, sold_engine_vehicles);
                }
                catch (car_no_exist &kapsula) {
                    cout << kapsula.msg << endl;
                }

                Varnisher::changeColor(sold_engine_vehicles.at(tmp_i), plik);
            }

            default: {
                break;
            }
        }
    } while(W != 0);
    return 0;
}