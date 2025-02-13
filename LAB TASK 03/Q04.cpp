#include <iostream>
#include <cstdlib>  
using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    double monthlySalary;

public:
    Employee(string fName, string lName, double salary) {
        firstName = fName;
        lastName = lName;
        setMonthlySalary(salary);
    }

    void setMonthlySalary(double salary) {
        if (salary > 0) {
            monthlySalary = salary;
        } else {
            monthlySalary = 0.0;
        }
    }

    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    double getMonthlySalary() { return monthlySalary; }
    double getYearlySalary() { return monthlySalary * 12; }

    void giveRaise() {
        monthlySalary *= 1.10;
    }

    void displayEmployee() {
        cout << "Employee: " << firstName << " " << lastName << "\n";
        cout << "Monthly Salary: $" << monthlySalary << "\n";
        cout << "Yearly Salary: $" << getYearlySalary() << "\n\n";
    }
};

int main(int argc, char* argv[]) {
    if (argc < 7) {
        cout << "Enter Right Inputs";
        return 1;
    }

    string first1 = argv[1];
    string last1 = argv[2];
    double salary1 = atof(argv[3]);

    string first2 = argv[4];
    string last2 = argv[5];
    double salary2 = atof(argv[6]);

    Employee emp1(first1, last1, salary1);
    Employee emp2(first2, last2, salary2);

    cout << "Initial Salaries:\n";
    emp1.displayEmployee();
    emp2.displayEmployee();

    emp1.giveRaise();
    emp2.giveRaise();

    cout << "After 10% Raise:\n";
    emp1.displayEmployee();
    emp2.displayEmployee();

    return 0;
}
