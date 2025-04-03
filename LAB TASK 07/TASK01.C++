#include <iostream>
#include <cstring>

using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    char accountHolderName[50];
    char accountType[20]; 
    int transactionCount;
    double transactions[100]; 

public:
    Account(int accNo, double bal, const char* name, const char* type = "General") {
        accountNumber = accNo;
        balance = bal;
        strcpy(accountHolderName, name);
        strcpy(accountType, type);
        transactionCount = 0;
    }

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions[transactionCount++] = amount;
            cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactions[transactionCount++] = -amount; 
            cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    virtual void calculateInterest() = 0; 

    virtual void printStatement() {
        cout << "\n--- Account Statement ---\n";
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Transactions:\n";
        for (int i = 0; i < transactionCount; i++) {
            cout << (transactions[i] > 0 ? "Deposit: $" : "Withdraw: $") << abs(transactions[i]) << endl;
        }
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNo, double bal, const char* name, double rate, double minBal)
        : Account(accNo, bal, name, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = (balance * interestRate) / 100;
        balance += interest;
        transactions[transactionCount++] = interest; 
        cout << "Interest Added: $" << interest << " | New Balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount < minimumBalance) {
            cout << "Withdrawal denied! Must maintain minimum balance of $" << minimumBalance << endl;
        } else {
            Account::withdraw(amount);
        }
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, double bal, const char* name, double overdraft)
        : Account(accNo, bal, name, "Checking"), overdraftLimit(overdraft) {}

    void calculateInterest() override {
        cout << "No interest for Checking Accounts." << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            Account::withdraw(amount);
        } else {
            cout << "Withdrawal denied! Overdraft limit exceeded." << endl;
        }
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    int maturityPeriod; 

public:
    FixedDepositAccount(int accNo, double bal, const char* name, double rate, int period)
        : Account(accNo, bal, name, "Fixed Deposit"), fixedInterestRate(rate), maturityPeriod(period) {}

    void calculateInterest() override {
        double interest = (balance * fixedInterestRate * maturityPeriod) / (100 * 12);
        balance += interest;
        transactions[transactionCount++] = interest; 
        cout << "Fixed Deposit Interest Added: $" << interest << " | New Balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        cout << "Cannot withdraw before maturity period!" << endl;
    }
};

int main() {
    SavingsAccount sa(1, 5000, "Ahmed", 3.5, 1000);
    CheckingAccount ca(2, 3000, "Affan", 500);
    FixedDepositAccount fda(3, 10000, "Raza", 5.0, 12);

    cout << "\n[Savings Account Transactions]\n";
    sa.deposit(2000);
    sa.withdraw(4000);
    sa.withdraw(3500); 
    sa.calculateInterest();
    sa.printStatement();

    cout << "\n[Checking Account Transactions]\n";
    ca.deposit(1500);
    ca.withdraw(5000); 
    ca.withdraw(2000); 
    ca.calculateInterest();
    ca.printStatement();

    cout << "\n[Fixed Deposit Account Transactions]\n";
    fda.calculateInterest();
    fda.withdraw(5000); 
    fda.printStatement();

    return 0;
}
