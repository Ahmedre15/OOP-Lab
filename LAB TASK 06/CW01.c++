#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    double balance;
    bool frozen; // To track if an account is frozen

public:
    BankAccount(int AN, double B) : accountNumber(AN), balance(B), frozen(false) {}

    virtual void deposit(double amount) {
        if (frozen) {
            cout << "Account is frozen. Cannot deposit.\n";
            return;
        }
        balance += amount;
        cout << "Deposited Amount: " << amount << "\nCurrent Balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (frozen) {
            cout << "Account is frozen. Cannot withdraw.\n";
            return;
        }
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn Amount: " << amount << "\nCurrent Balance: " << balance << endl;
        } else {
            cout << "Insufficient Balance" << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << "\nBalance: " << balance << endl;
    }

    void freezeAccount() {
        frozen = true;
        cout << "Account " << accountNumber << " is now frozen.\n";
    }

    void unfreezeAccount() {
        frozen = false;
        cout << "Account " << accountNumber << " is now active.\n";
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    double interestRate;

    SavingsAccount(int AN, double B, double I) : BankAccount(AN, B), interestRate(I) {}

    void applyMonthlyUpdate() {
        balance += balance * interestRate;
        cout << "Interest Applied. New Balance: " << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
public:
    double overdraftLimit;

    CheckingAccount(int AN, double B, double odL) : BankAccount(AN, B), overdraftLimit(odL) {}

    void withdraw(double amount) override {
        if (frozen) {
            cout << "Account is frozen. Cannot withdraw.\n";
            return;
        }
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
            if (balance < 0)
                cout << "Alert: Overdraft used!" << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }
};

class BusinessAccount : public BankAccount {
public:
    double taxRate;

    BusinessAccount(int AN, double B, double tax) : BankAccount(AN, B), taxRate(tax) {}

    void deposit(double amount) override {
        if (frozen) {
            cout << "Account is frozen. Cannot deposit.\n";
            return;
        }
        double tax = amount * taxRate;
        balance += (amount - tax);
        cout << "Deposited: " << amount << " | Tax Deducted: " << tax
             << " | New Balance: " << balance << endl;
    }
};

class Employee {
protected:
    string name;
    int ID;

public:
    Employee(string n, int id) : name(n), ID(id) {}

    virtual void displayRole() = 0; 
};

class Customer {
protected:
    string name;
    int ID;
    BankAccount* account; 

public:
    Customer(string n, int id, BankAccount* acc) : name(n), ID(id), account(acc) {}

    void deposit(double amount) {
        account->deposit(amount);
    }

    void withdraw(double amount) {
        account->withdraw(amount);
    }

    void viewAccount() {
        account->display();
    }
};


class Teller : public Employee {
public:
    Teller(string n, int id) : Employee(n, id) {}

    void deposit(Customer& customer, double amount) {
        customer.deposit(amount);
    }

    void withdraw(Customer& customer, double amount) {
        customer.withdraw(amount);
    }

    void freezeAccount(BankAccount* account) {
        account->freezeAccount();
    }

    void unfreezeAccount(BankAccount* account) {
        account->unfreezeAccount();
    }

    void displayRole() override {
        cout << "Role: Teller\n";
    }
};


class Manager : public Employee {
public:
    Manager(string n, int id) : Employee(n, id) {}

    void overrideLimit(CheckingAccount& account, double newLimit) {
        account.overdraftLimit = newLimit;
        cout << "Overdraft limit updated to: " << newLimit << endl;
    }

    void displayRole() override {
        cout << "Role: Manager\n";
    }
};

int main() {
    SavingsAccount sa(101, 5000, 0.02);
    CheckingAccount ca(102, 3000, 10000);
    BusinessAccount ba(103, 8000, 0.05);

    Customer customer1("Alice", 1, &sa);
    Customer customer2("Bob", 2, &ca);

    Teller teller("John", 101);
    Manager manager("Sarah", 201);

    cout << "\n--- Customer Operations ---\n";
    customer1.deposit(1000);
    customer1.withdraw(2000);
    customer1.viewAccount();

    cout << "\n--- Teller Freezing Account ---\n";
    teller.freezeAccount(&sa);
    customer1.deposit(500); 

    cout << "\n--- Manager Adjusting Overdraft Limit ---\n";
    manager.overrideLimit(ca, 15000);
    customer2.withdraw(13000); 

    return 0;
}
