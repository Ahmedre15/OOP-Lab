#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    float salary;

public:
    virtual void getData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void displayData() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary;
    }

    virtual void bonus() {
        cout << " (Base Class Bonus: $" << 0.0 << ")\n";
    }

    virtual ~Person() {}
};

class Admin : virtual public Person {
public:
    void getData() override {
        cout << "[Admin Info]\n";
        Person::getData();
    }

    void displayData() override {
        cout << "[Admin] ";
        Person::displayData();
    }

    void bonus() override {
        cout << " (Admin Bonus: $" << 0.1 * salary << ")\n";
    }
};

class Account : virtual public Person {
public:
    void getData() override {
        cout << "[Account Info]\n";
        Person::getData();
    }

    void displayData() override {
        cout << "[Account] ";
        Person::displayData();
    }

    void bonus() override {
        cout << " (Account Bonus: $" << 0.08 * salary << ")\n";
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        cout << "[Master Info]\n";
        Person::getData();
    }

    void displayData() override {
        cout << "[Master] ";
        Person::displayData();
    }

    void bonus() override {
        cout << " (Master Bonus: $" << 0.15 * salary << ")\n";
    }
};

int main() {
    const int SIZE = 3;
    Person* staff[SIZE];

    staff[0] = new Admin();
    staff[1] = new Account();
    staff[2] = new Master();

    for (int i = 0; i < SIZE; ++i) {
        cout << "\n--- Enter Data for Employee " << i + 1 << " ---\n";
        staff[i]->getData();
    }

    cout << "\n===== Employee Details and Bonuses =====\n";
    for (int i = 0; i < SIZE; ++i) {
        staff[i]->displayData();
        staff[i]->bonus();
    }

    for (int i = 0; i < SIZE; ++i) {
        delete staff[i];
    }

    return 0;
}
