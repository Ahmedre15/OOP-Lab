#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    float price;

public:
    void setModel(const string& m) {
        model = m;
    }

    string getModel() const {
        return model;
    }

    float getPrice() const {
        return price;
    }

 
    virtual void setPrice(float p) = 0;
 
    virtual ~Car() {}
};


class Color : public Car {
private:
    string carColor;

public:
    Color(const string& m, const string& c, float p) {
        setModel(m);
        carColor = c;
        setPrice(p);
    }

    void setPrice(float p) override {

        if (p > 0)
            price = p;
        else
            price = 0;
    }

    void display() const {
        cout << "Model: " << model
             << " | Color: " << carColor
             << " | Price: $" << price << endl;
    }
};
class Company : public Car {
private:
    string companyName;

public:
    Company(const string& m, const string& comp, float p) {
        setModel(m);
        companyName = comp;
        setPrice(p);
    }

    void setPrice(float p) override {
        price = (p >= 1000) ? p : 1000; 
    }

    void display() const {
        cout << "Model: " << model
             << " | Company: " << companyName
             << " | Price: $" << price << endl;
    }
};

int main() {
 
    Color c1("Civic", "Red", 30000);
    c1.display();

    Company c2("Model S", "Tesla", 950);
    c2.display();

    return 0;
}
