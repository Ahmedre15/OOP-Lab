#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Shape {
protected:
    double positionX, positionY;  
    char color[20];
    double borderThickness;

public:
    Shape(double x, double y, const char* col, double border = 1.0) {
        positionX = x;
        positionY = y;
        strcpy(color, col);
        borderThickness = border;
    }

    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;

    void displayProperties() {
        cout << "Position: (" << positionX << ", " << positionY << ")\n";
        cout << "Color: " << color << "\n";
        cout << "Border Thickness: " << borderThickness << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double x, double y, const char* col, double r, double border = 1.0)
        : Shape(x, y, col, border), radius(r) {}

    void draw() override {
        cout << "Drawing a Circle at (" << positionX << ", " << positionY << ") with Radius: " << radius << endl;
    }

    double calculateArea() override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double x, double y, const char* col, double w, double h, double border = 1.0)
        : Shape(x, y, col, border), width(w), height(h) {}

    void draw() override {
        cout << "Drawing a Rectangle at (" << positionX << ", " << positionY << ") with Width: " << width << " and Height: " << height << endl;
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double sideA, sideB, sideC;

public:
    Triangle(double x, double y, const char* col, double a, double b, double c, double border = 1.0)
        : Shape(x, y, col, border), sideA(a), sideB(b), sideC(c) {}

    void draw() override {
        cout << "Drawing a Triangle at (" << positionX << ", " << positionY << ") with Sides: " << sideA << ", " << sideB << ", " << sideC << endl;
    }

    double calculateArea() override {
        double s = (sideA + sideB + sideC) / 2;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));  
    }

    double calculatePerimeter() override {
        return sideA + sideB + sideC;
    }
};
class Polygon : public Shape {
private:
    int sides;
    double sideLength;

public:
    Polygon(double x, double y, const char* col, int s, double len, double border = 1.0)
        : Shape(x, y, col, border), sides(s), sideLength(len) {}

    void draw() override {
        cout << "Drawing a Polygon with " << sides << " sides at (" << positionX << ", " << positionY << ") and Side Length: " << sideLength << endl;
    }

    double calculateArea() override {
        return (sides * sideLength * sideLength) / (4 * tan(M_PI / sides));
    }

    double calculatePerimeter() override {
        return sides * sideLength;
    }
};

int main() {
    Circle c(5, 5, "Voilet", 10);
    Rectangle r(2, 2, "Indigo", 4, 6);
    Triangle t(1, 1, "Yellow", 3, 4, 5);
    Polygon p(0, 0, "Blavk", 6, 4);

    cout << "\n[Circle]\n";
    c.draw();
    c.displayProperties();
    cout << "Area: " << c.calculateArea() << endl;
    cout << "Perimeter: " << c.calculatePerimeter() << endl;

    cout << "\n[Rectangle]\n";
    r.draw();
    r.displayProperties();
    cout << "Area: " << r.calculateArea() << endl;
    cout << "Perimeter: " << r.calculatePerimeter() << endl;

    cout << "\n[Triangle]\n";
    t.draw();
    t.displayProperties();
    cout << "Area: " << t.calculateArea() << endl;
    cout << "Perimeter: " << t.calculatePerimeter() << endl;

    cout << "\n[Polygon]\n";
    p.draw();
    p.displayProperties();
    cout << "Area: " << p.calculateArea() << endl;
    cout << "Perimeter: " << p.calculatePerimeter() << endl;

    return 0;
}
