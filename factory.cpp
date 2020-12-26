#include "factory.h"

using namespace std;

Factory::Factory(string name) {
    this -> name = name;
}
    
void Factory::addNewCar(string color, int door_count) {
    Car car = Car("Factory", color, this -> name, door_count);
    this -> garage.push_back(car);
}

void Factory::sell(Car car){
    for(int i=0; i < this->garage.size();i++){
        if(this -> garage.at(i) == car){
            cout << "Siema";
        }
    }
}

void Factory::print(){
    for(int i = 0; i < this->garage.size(); i++) {
        cout << this -> garage.at(i) << endl;
    }
}