#include <iostream>
/*According to different sources:-A const function cannot modify member variables, so you can't directly change values using a constant function.*/
using namespace std;

class Car {
    int engineHorsepower;
    int seatingCapacity;
    int noOfSpeakers;

public:
    Car(int hp, int seats, int speakers) : engineHorsepower(hp), seatingCapacity(seats), noOfSpeakers(speakers) {}

    void setCarAttributes(int hp, int seats, int speakers) {
        engineHorsepower = hp;
        seatingCapacity = seats;
        noOfSpeakers = speakers;
    }

    void displayCar() const {
        cout << "Engine Horsepower: " << engineHorsepower << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Speakers: " << noOfSpeakers << endl;
    }
};

int main() {
    Car myCar(200, 5, 6);
    myCar.displayCar();

    myCar.setCarAttributes(250, 4, 8);
    cout << "\nAfter Modifications:\n";
    myCar.displayCar();
/*This program allows changing the attributes via a setter function but ensures displayCar() is a const function, meaning it won't modify the object.*/
    return 0;
}
