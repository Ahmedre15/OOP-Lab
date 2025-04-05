#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int commonDivisor = gcd(numerator, denominator);
        numerator /= commonDivisor;
        denominator /= commonDivisor;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (den == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Cannot divide by a fraction with numerator 0.");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(other < *this);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        f.reduce();
        return is;
    }
};

int main() {
    try {
        Fraction f1(2, 4), f2(3, 6);
        cout << "f1: " << f1 << endl;
        cout << "f2: " << f2 << endl;

        cout << "f1 + f2: " << (f1 + f2) << endl;
        cout << "f1 - f2: " << (f1 - f2) << endl;
        cout << "f1 * f2: " << (f1 * f2) << endl;
        cout << "f1 / f2: " << (f1 / f2) << endl;

        cout << "f1 == f2: " << (f1 == f2) << endl;
        cout << "f1 != f2: " << (f1 != f2) << endl;
        cout << "f1 < f2: " << (f1 < f2) << endl;
        cout << "f1 > f2: " << (f1 > f2) << endl;
        cout << "f1 <= f2: " << (f1 <= f2) << endl;
        cout << "f1 >= f2: " << (f1 >= f2) << endl;

        Fraction f3(0, 1);
        cout << "Enter a fraction (format: numerator/denominator): ";
        cin >> f3;
        cout << "You entered: " << f3 << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
