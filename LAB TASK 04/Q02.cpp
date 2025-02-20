#include <iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance < 0 ? 0 : initialBalance) {}

    void credit(double amount) {
        balance += amount;
    }

    void debit(double amount) {
        if (amount > balance)
            cout << "Debit amount exceeded account balance." << endl;
        else
            balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    Account acc(1000);

    acc.credit(500);
    cout << "Balance after credit: " << acc.getBalance() << endl;

    acc.debit(300);
    cout << "Balance after debit: " << acc.getBalance() << endl;

    acc.debit(1500);
    cout << "Balance after failed debit: " << acc.getBalance() << endl;

    return 0;
}
