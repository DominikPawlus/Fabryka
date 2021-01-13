#include "office.h"

void Office::register(Engine_Vehicle &e_vehicle, std::ifstream &plik) {

    int numer =( std::rand() % 99999 ) + 10000;
    std::string number = std::to_string(numer);
    std::string prefix;
    int W;

    if(plik.is_open()) {
        plik >> W;
    } else {
            std::cout << "Wybierz województwo: " <<
            std::endl;
            std::cout << "(1) -dolnośląskie\n"
                "(2) -kujawsko-pomorskie\n"
                "(3) -lubelskie\n"
                "(4) -lubuskie\n"
                "(5) -łódzkie\n"
                "(6) -małopolskie\n"
                "(7) -mazowieckie\n"
                "(8) -opolskie\n"
                "(9) -podkarpackie\n"
                "(10) -podlaskie\n"
                "(11) -pomorskie\n"
                "(12) -śląskie\n"
                "(13) -świętokrzyskie\n"
                "(14) -warmińsko-mazurskie\n"
                "(15) -wielkopolskie\n"
                "(16) -zachodniopomorskie" <<
            std::endl;
            cin >> W;
        }

    switch(W) {

        case(1): {
            prefix = "D";
            break;
        }
        case(2): {
            prefix = "C";
            break;
        }
        case(3): {
            prefix = "L";
            break;
        }
        case(4): {
            prefix = "F";
            break;
        }
        case(5): {
            prefix = "E";
            break;
        }
        case(6): {
            prefix = "K";
            break;
        }
        case(7): {
            prefix = "W";
            break;
        }
        case(8): {
            prefix = "O";
            break;
        }
        case(9): {
            prefix = "R";
            break;
        }
        case(10): {
            prefix = "B";
            break;
        }
        case(11): {
            prefix = "G";
            break;
        }
        case(12): {
            prefix = "S";
            break;
        }
        case(13): {
            prefix = "T";
            break;
        }
        case(14): {
            prefix = "N";
            break;
        }
        case(15): {
            prefix = "P";
            break;
        }
        case(16): {
            prefix = "Z";
            break;
        }


    }

    number = prefix + number;

    e_vehicle.license_plate = true;
    e_vehicle.number = number;
    std::cout << "Zarejestrowano pojazd. Numer rejestracyjny: " << number << std::endl;
}