#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
private:
    double* coefficients;
    int degree;

public:
    Polynomial() {
        degree = 0;
        coefficients = new double[1];
        coefficients[0] = 0;
    }

    Polynomial(int deg, const double* coeffs) {
        degree = deg;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = coeffs[i];
        }
    }

    Polynomial(const Polynomial& other) {
        degree = other.degree;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = other.coefficients[i];
        }
    }

    Polynomial(Polynomial&& other) noexcept {
        degree = other.degree;
        coefficients = other.coefficients;
        other.coefficients = nullptr;
        other.degree = 0;
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= degree; i++) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        double* sumCoeffs = new double[maxDegree + 1]();

        for (int i = 0; i <= degree; i++) sumCoeffs[i] += coefficients[i];
        for (int i = 0; i <= other.degree; i++) sumCoeffs[i] += other.coefficients[i];

        Polynomial result(maxDegree, sumCoeffs);
        delete[] sumCoeffs;
        return result;
    }

    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double* productCoeffs = new double[newDegree + 1]();

        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                productCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        Polynomial result(newDegree, productCoeffs);
        delete[] productCoeffs;
        return result;
    }

    void print() const {
        bool firstTerm = true;
        for (int i = degree; i >= 0; --i) {
            if (coefficients[i] != 0) {
                if (!firstTerm) {
                    cout << " + ";
                }
                cout << coefficients[i];
                if (i > 0) {
                    cout << "x^" << i;
                }
                firstTerm = false;
            }
        }
        cout << endl;
    }
    
};

int main() {
    double coeffs1[] = {1.0, 2.0, 3.0};
    Polynomial poly1(2, coeffs1);
    cout << "Initializing poly1" << endl;
    cout << "Polynomial poly1: ";
    poly1.print();

    Polynomial poly2 = poly1;
    cout << "\nCopied poly1 to poly2" << endl;
    cout << "Polynomial poly2: ";
    poly2.print();

    Polynomial poly3 = move(poly1);
    cout << "\nMoved poly1 to poly3" << endl;
    cout << "Polynomial poly3: ";
    poly3.print();

    cout << "\nEvaluate poly3 at x = 2: " << poly3.evaluate(2) << endl;

    Polynomial poly4 = poly2.add(poly3);
    cout << "\nPolynomial poly4 (poly2 + poly3): ";
    poly4.print();

    Polynomial poly5 = poly2.multiply(poly3);
    cout << "\nPolynomial poly5 (poly2 * poly3): ";
    poly5.print();

    return 0;
}
