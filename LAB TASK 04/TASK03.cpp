#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray() : size(0), data(nullptr) {}

    DynamicArray(int n) : size(n) {
        data = new int[size]();
    }

    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    DynamicArray(DynamicArray&& other) noexcept : size(other.size), data(other.data) {
        other.size = 0;
        other.data = nullptr;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = other.data;
            other.size = 0;
            other.data = nullptr;
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }

    int GetSize() const {
        return size;
    }

    int& AtLocation(int index) {
        return data[index];
    }

    void Resize(int newSize) {
        int* newData = new int[newSize]();
        for (int i = 0; i < (newSize < size ? newSize : size); i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

    void Print() const {
        if (size == 0) {
            cout << "(Empty Array)" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
};

int main() {
    DynamicArray empty;
    cout << "Testing Default Constructor" << endl << "Empty array: ";
    empty.Print();

    DynamicArray D1(5);
    D1.AtLocation(0) = 10;
    D1.AtLocation(3) = 20;
    cout << endl << "Testing Parametrized Constructor!" << endl << "Array D1: ";
    D1.Print();

    DynamicArray D2 = D1;
    cout << endl << "Testing Copy Constructor" << endl << "Copying D1 to D2 Array: ";
    D2.Print();

    DynamicArray D3 = move(D1);
    cout << endl << "Testing Move Constructor" << endl;
    cout << "Array D3 (moved from D1): ";
    D3.Print();
    cout << "Original D1 after move: ";
    D1.Print();

    DynamicArray D4;
    D4 = D3;
    cout << endl << "Testing Copy Assignment Operator" << endl;
    cout << "Array D4 (copy of D3): ";
    D4.Print();

    DynamicArray D5;
    D5 = move(D3);
    cout << endl << "Testing Move Assignment Operator" << endl;
    cout << "Array D5 (moved from D3): ";
    D5.Print();
    cout << "Original D3 after move: ";
    D3.Print();

    cout << endl << "Size of Array D5: " << D5.GetSize() << endl;

    D5.Resize(6);
    D5.AtLocation(5) = 50;
    cout << endl << "Testing Resize" << endl;
    cout << "Array D5 after resize(6): ";
    D5.Print();

    D5.Resize(4);
    cout << "Array D5 after resize(4): ";
    D5.Print();

    D5.Resize(0);
    cout << "Array D5 after resize(0): ";
    D5.Print();

    return 0;
}
