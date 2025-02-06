#include <iostream>
#include <cstdlib>
using namespace std;

int* resizeArray(int* oldArray, int oldSize, int newSize) {
    int* newArray = new int[newSize];
    for (int i = 0; i < oldSize; i++) {
        newArray[i] = oldArray[i];
    }
    delete[] oldArray;
    return newArray;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <list of numbers>" << endl;
        return 1;
    }

    int size = 5;
    int count = 0;
    int* arr = new int[size];

    for (int i = 1; i < argc; i++) {
        if (count >= size) {
            size = size * 2;
            arr = resizeArray(arr, count, size);
        }
        arr[count] = atoi(argv[i]);
        count++;
    }

    arr = resizeArray(arr, count, count);

    cout << "Final array size: " << count << endl;
    cout << "Final array elements: ";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
