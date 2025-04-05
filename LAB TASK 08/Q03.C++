#include <iostream>
using namespace std;

class Person {
protected:
    int employeeID;

public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }

    void displayData() {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
private:
    string name;
    float monthlyIncome;
    float bonusAmount;

public:
    void getData() {
        Person::getData();
        cout << "Enter Admin Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void bonus() {
        bonusAmount = monthlyIncome * 0.05;
    }

    void displayData() {
        Person::displayData();
        cout << "Admin Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonusAmount << endl;
    }
};

class Accounts : public Person {
private:
    string name;
    float monthlyIncome;
    float bonusAmount;

public:
    void getData() {
        Person::getData();
        cout << "Enter Accounts Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void bonus() {
        bonusAmount = monthlyIncome * 0.05;
    }

    void displayData() {
        Person::displayData();
        cout << "Accounts Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonusAmount << endl;
    }
};

int main() {
    Admin adminEmp;
    Accounts accountsEmp;

    cout << "--- Enter Admin Info ---" << endl;
    adminEmp.getData();
    adminEmp.bonus();

    cout << "\n--- Enter Accounts Info ---" << endl;
    accountsEmp.getData();
    accountsEmp.bonus();

    cout << "\n--- Admin Employee Details ---" << endl;
    adminEmp.displayData();

    cout << "\n--- Accounts Employee Details ---" << endl;
    accountsEmp.displayData();

    return 0;
}
