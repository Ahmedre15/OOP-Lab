#include <iostream>
using namespace std;

class Shape {
private:
    float area;

public:
    Shape() {
        area = 0;
    }

    Shape(float a) {
        area = a;
    }

    float Area() const {
        return area;
    }

    Shape operator+(const Shape& s) {
        return Shape(this->area + s.area);
    }

    void display() {
        cout << "Area: " << area << endl;
    }
};

int main() {
    Shape shape1(25.5);
    Shape shape2(34.5);

    cout << "Shape 1: ";
    shape1.display();

    cout << "Shape 2: ";
    shape2.display();

    Shape shape3 = shape1 + shape2;
    cout << "After Adding Areas: ";
    shape3.display();

    return 0;
}
