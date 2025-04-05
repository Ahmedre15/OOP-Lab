#include <iostream>
using namespace std;

const int MAX_DEGREE = 11;

class Polynomial;

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x);
    static Polynomial derivative(const Polynomial& p);
};

class Polynomial {
private:
    int coeffs[MAX_DEGREE];

public:
    Polynomial() {
        for (int i = 0; i < MAX_DEGREE; i++)
            coeffs[i] = 0;
    }

    Polynomial(int inputCoeffs[], int size) {
        for (int i = 0; i < MAX_DEGREE; i++)
            coeffs[i] = (i < size) ? inputCoeffs[i] : 0;
    }

    Polynomial operator+(const Polynomial& other) const {
        Polynomial result;
        for (int i = 0; i < MAX_DEGREE; i++)
            result.coeffs[i] = coeffs[i] + other.coeffs[i];
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        Polynomial result;
        for (int i = 0; i < MAX_DEGREE; i++)
            result.coeffs[i] = coeffs[i] - other.coeffs[i];
        return result;
    }

    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;
        for (int i = 0; i < MAX_DEGREE; i++) {
            for (int j = 0; j < MAX_DEGREE; j++) {
                if (i + j < MAX_DEGREE)
                    result.coeffs[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        return result;
    }

    friend ostream& operator<<(ostream& out, const Polynomial& p) {
        bool first = true;
        for (int i = MAX_DEGREE - 1; i >= 0; i--) {
            if (p.coeffs[i] != 0) {
                if (!first && p.coeffs[i] > 0) out << " + ";
                if (p.coeffs[i] < 0) out << " - ";
                if (abs(p.coeffs[i]) != 1 || i == 0)
                    out << abs(p.coeffs[i]);
                if (i > 0) out << "x";
                if (i > 1) out << "^" << i;
                first = false;
            }
        }
        if (first) out << "0";
        return out;
    }

    friend class PolynomialUtils;
};

int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0;
    int power = 1;
    for (int i = 0; i < MAX_DEGREE; i++) {
        result += p.coeffs[i] * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    Polynomial result;
    for (int i = 1; i < MAX_DEGREE; i++) {
        result.coeffs[i - 1] = p.coeffs[i] * i;
    }
    return result;
}

int main() {
    int arr1[] = {1, 2, 3};       // 3x^2 + 2x + 1
    int arr2[] = {0, -1, 2};      // 2x^2 - x

    Polynomial p1(arr1, 3);
    Polynomial p2(arr2, 3);

    cout << "P1 = " << p1 << endl;
    cout << "P2 = " << p2 << endl;

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    cout << "P1 + P2 = " << sum << endl;
    cout << "P1 - P2 = " << diff << endl;
    cout << "P1 * P2 = " << prod << endl;

    cout << "P1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << "Derivative of P1: " << PolynomialUtils::derivative(p1) << endl;

    return 0;
}
