#include <iostream>
#include <cstring>

using namespace std;

class Currency {
protected:
    double amount;
    char currencyCode[5];
    char currencySymbol[5];
    double exchangeRate;  

public:
    Currency(double amt, const char* code, const char* symbol, double rate) {
        amount = amt;
        strcpy(currencyCode, code);
        strcpy(currencySymbol, symbol);
        exchangeRate = rate;
    }

    virtual double convertToBase() = 0;  
    
    virtual double convertTo(Currency& targetCurrency) {
        double amountInBase = convertToBase();
        return amountInBase / targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() {
        cout << currencySymbol << amount << " (" << currencyCode << ")\n";
    }

    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}  

    double convertToBase() override {
        return amount;  
    }

    void displayCurrency() override {
        cout << "USD Amount: " << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {} 

    double convertToBase() override {
        return amount * exchangeRate;  
    }

    void displayCurrency() override {
        cout << "Euro Amount: " << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs ", 0.012) {}  

    double convertToBase() override {
        return amount * exchangeRate; 
    }

    void displayCurrency() override {
        cout << "Rupee Amount: " << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

int main() {
    Dollar usd(100);
    Euro eur(50);
    Rupee pkr(5000);

    cout << "\n[Currency Details]\n";
    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();

    cout << "\n[Conversions]\n";
    cout << "50 EUR to USD: $" << eur.convertTo(usd) << endl;
    cout << "5000 PKR to USD: $" << pkr.convertTo(usd) << endl;
    cout << "100 USD to PKR: Rs " << usd.convertTo(pkr) << endl;

    return 0;
}
