#include <iostream>

using namespace std;

class Matrix {
public:
    int rows, cols;
    int elements[10][10]; 

    Matrix(int r, int c) {
        rows = r;
        cols = c;
    }

    int getRows() { return rows; }

    int getCols() { return cols; }

    void setElement(int i, int j, int value) {
        elements[i][j] = value;
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(Matrix other) {
        if (this->rows != other.rows || this->cols != other.cols) {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.elements[i][j] = this->elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }

    Matrix multiply(Matrix other) {
        if (this->cols != other.rows) {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);
        }

        Matrix result(this->rows, other.cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.elements[i][j] = 0;
                for (int k = 0; k < this->cols; k++) {
                    result.elements[i][j] += this->elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for Matrix 1: ";
    cin >> r1 >> c1;
    Matrix A(r1, c1);

    cout << "Enter elements of Matrix 1:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A.elements[i][j];

    cout << "Enter rows and columns for Matrix 2: ";
    cin >> r2 >> c2;
    Matrix B(r2, c2);

    cout << "Enter elements of Matrix 2:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B.elements[i][j];

    cout << "\nMatrix 1:\n";
    A.display();

    cout << "\nMatrix 2:\n";
    B.display();

    if (r1 == r2 && c1 == c2) {
        cout << "\nAddition Result:\n";
        Matrix sum = A.add(B);
        sum.display();
    } else {
        cout << "\nMatrices cannot be added!\n";
    }

    if (c1 == r2) {
        cout << "\nMultiplication Result:\n";
        Matrix product = A.multiply(B);
        product.display();
    } else {
        cout << "\nMatrices cannot be multiplied!\n";
    }

    return 0;
}
