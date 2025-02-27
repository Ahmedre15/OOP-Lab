#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
private:
    int ID;
    string name;

public:
    Car(int id, const string& name) : ID(id), name(name) {}

    int getID() const { return ID; }
    string getName() const { return name; }
};

class Garage {
private:
    vector<Car*> cars;

public:
    void parkCar(Car* car) {
        cars.push_back(car);
    }

    void listCars() const {
        if (cars.empty()) {
            cout << "No cars in the Garage" << endl;
        } else {
            cout << "Cars in the Garage:" << endl;
            for (const auto& car : cars) {
                cout << "ID: " << car->getID() << ", Name: " << car->getName() << endl;
            }
        }
    }
};

int main() {
    Car car1(1, "Toyota");
    Car car2(2, "Corolla");
    Car car3(3, "Mehran");

    Garage garage;
    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);

    garage.listCars();

    return 0;
}
