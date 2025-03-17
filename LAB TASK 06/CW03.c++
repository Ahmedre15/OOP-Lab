#include <iostream>
using namespace std;

class Employee {
protected:
    int id;
    string name;

public:
    Employee(int i, string n) : id(i), name(n) {}
    virtual void showRole() = 0;
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder(string order) = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder(string order) = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill(double amount) = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int i, string n) : Employee(i, n) {}
    void takeOrder(string order) override { cout << name << " took order: " << order << endl; }
    void showRole() override { cout << "Role: Waiter\n"; }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int i, string n) : Employee(i, n) {}
    void prepareOrder(string order) override { cout << name << " prepared: " << order << endl; }
    void showRole() override { cout << "Role: Chef\n"; }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int i, string n) : Employee(i, n) {}
    void generateBill(double amount) override { cout << name << " generated bill: $" << amount << endl; }
    void showRole() override { cout << "Role: Cashier\n"; }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int i, string n) : Employee(i, n) {}
    void takeOrder(string order) override { cout << name << " took order as Manager: " << order << endl; }
    void generateBill(double amount) override { cout << name << " approved bill: $" << amount << endl; }
    void showRole() override { cout << "Role: Manager\n"; }
};

class Menu {
protected:
    string name;
public:
    Menu(string n) : name(n) {}
    virtual double calculateTotal(double price) = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    FoodMenu(string n) : Menu(n) {}
    double calculateTotal(double price) override { return price; }
};

class BeverageMenu : public Menu {
public:
    BeverageMenu(string n) : Menu(n) {}
    double calculateTotal(double price) override { return price * 1.1; }
};

int main() {
    FoodMenu food("Food Menu");
    double foodTotal = food.calculateTotal(20);
    
    BeverageMenu beverage("Beverage Menu");
    double beverageTotal = beverage.calculateTotal(10);
    
    double totalBill = foodTotal + beverageTotal;
    
    Waiter w(101, "Ali");
    w.takeOrder("Bun");
    
    Chef c(102, "Beta");
    c.prepareOrder("BBQ");
    
    Cashier cashier(103, "Chris");
    cashier.generateBill(totalBill);
    
    Manager m(104, "Demit");
    m.takeOrder("Pizza");
    m.generateBill(totalBill);
    
    return 0;
}
