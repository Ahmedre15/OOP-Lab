#include <iostream>
#include <cstring> 
using namespace std;

class Matrix {
private:
    double** data;
    int rows, cols;

public:
    Matrix() : rows(0), cols(0), data(nullptr) {}

    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols]{0};
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            std::memcpy(data[i], other.data[i], cols * sizeof(double));
        }
    }

    Matrix(Matrix&& other) : rows(other.rows), cols(other.cols), data(other.data) {
        other.rows = 0;
        other.cols = 0;
        other.data = nullptr;
    }

    ~Matrix() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    double& at(int r, int c) {
        return data[r][c];
    }

    void fill(double value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = value;
            }
        }
    }

    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed.data[j][i] = data[i][j];
            }
        }
        return transposed;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix mat(3, 3);
    mat.fill(2);
    std::cout << "Original Matrix:" << std::endl;
    mat.print();

    Matrix transposedMat = mat.transpose();
    std::cout << "Transposed Matrix:" << std::endl;
    transposedMat.print();

    return 0;
}
