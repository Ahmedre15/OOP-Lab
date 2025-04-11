#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    int balance;
    int WDlimit;  
    int Dlimit;   
    const int maxWD = 15;
    const int maxD = 15;

public:
    Wallet(int B = 0) : balance(B), WDlimit(0), Dlimit(0) {}

    int getBalance() const {
        return balance;
    }

    int getWDlimit() const {
        return WDlimit;
    }

    int getDlimit() const {
        return Dlimit;
    }

    bool withdraw(int amount) {
        if (WDlimit >= maxWD) {
            cout << "Your Withdraw Limit for today is completed.\n";
            return false;
        }
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            WDlimit++;
            return true;
        } else {
            cout << "Invalid or insufficient balance for withdrawal.\n";
            return false;
        }
    }

    bool deposit(int amount) {
        if (Dlimit >= maxD) {
            cout << "Your Deposit Limit for today is completed.\n";
            return false;
        }
        if (amount > 0) {
            balance += amount;
            Dlimit++;
            return true;
        } else {
            cout << "Invalid deposit amount.\n";
            return false;
        }
    }
};

class User {
private:
    int userID;
    string name;
    Wallet wallet;

public:
    User(int ID, string N, int initialBalance = 0)
        : userID(ID), name(N), wallet(initialBalance) {}

    int getID() const {
        return userID;
    }

    string getName() const {
        return name;
    }

    void deposit(int amount) {
        if (wallet.deposit(amount)) {
            cout << name << " deposited $" << amount << " successfully.\n";
        }
    }

    void withdraw(int amount) {
        if (wallet.withdraw(amount)) {
            cout << name << " withdrew $" << amount << " successfully.\n";
        }
    }

    void checkBalance() const {
        cout << name << "'s Balance: $" << wallet.getBalance() << endl;
    }
        int getWDlimit() const {
        return wallet.getDlimit();
        cout<<"Limit: "<<wallet.getDlimit();
    }

    int getDlimit() const {
        return wallet.getWDlimit();
    }
};

int main() {
    User user1(101, "Izaan", 1000);
    User user2(102, "Talha", 500);

    user1.checkBalance();
    user1.deposit(200);
    user1.withdraw(150);
    user1.withdraw(1000); 
    user1.checkBalance();

    cout << "\n";

    user2.checkBalance();
    user2.withdraw(600); 
    user2.deposit(300);
    user2.checkBalance();
user1.getWDlimit();
user2.getWDlimit();

    return 0;
}
