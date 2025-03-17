#include <iostream>
using namespace std;

class Vehicle {
protected:
    double price;
public:
    Vehicle(double p) : price(p) {}
    virtual void displayDetails() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
protected:
    int seatingCapacity, numDoors;
    string fuelType;
public:
    Car(double p, int s, int d, string f) : Vehicle(p), seatingCapacity(s), numDoors(d), fuelType(f) {}
};

class Motorcycle : public Vehicle {
protected:
    int numCylinders, numGears, numWheels;
public:
    Motorcycle(double p, int c, int g, int w) : Vehicle(p), numCylinders(c), numGears(g), numWheels(w) {}
};

class Audi : public Car {
private:
    string modelType;
public:
    Audi(double p, int s, int d, string f, string m) : Car(p, s, d, f), modelType(m) {}
    void displayDetails() override {
        cout << "Audi Car Details:\n";
        cout << "Price: $" << price << "\nSeating Capacity: " << seatingCapacity 
             << "\nDoors: " << numDoors << "\nFuel Type: " << fuelType 
             << "\nModel Type: " << modelType << "\n";
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    Yamaha(double p, int c, int g, int w, string m) : Motorcycle(p, c, g, w), makeType(m) {}
    void displayDetails() override {
        cout << "Yamaha Motorcycle Details:\n";
        cout << "Price: Rs" << price << "\nCylinders: " << numCylinders
             << "\nGears: " << numGears << "\nWheels: " << numWheels
             << "\nMake Type: " << makeType << "\n";
    }
};

int main() {
    Audi myAudi(50000, 5, 4, "Petrol", "A6");
    Yamaha myYamaha(15000, 2, 6, 2, "R1");

    myAudi.displayDetails();
    cout << endl;
    myYamaha.displayDetails();

    return 0;
}