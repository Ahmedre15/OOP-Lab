#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() const {
        return 2 * 3.14159 * radius;
    }
};

int main() {
    double r;
    cout << "Enter radius: ";
    cin >> r;

    Circle c(r);
    cout << "Area: " << c.getArea() << endl;
    cout << "Perimeter: " << c.getPerimeter() << endl;

    return 0;
}
