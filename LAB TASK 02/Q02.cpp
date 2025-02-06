#include <iostream>
#include <cstdlib>
using namespace std;

void* add(void* ptr, int size) {
    int* numbers = (int*)ptr;
    for (int i = 0; i < size; i++) {
        numbers[i] += 5;  // Perform add operation(change 5 becuase no specific operation was given)
    }
    return numbers;  // Return modified array
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        int numbers[argc - 1];  

        for (int i = 1; i < argc; i++) {
            numbers[i - 1] = stoi(argv[i]);  
        }

        void* modifiedArray = add(numbers, argc - 1);
        int* result = (int*)modifiedArray;  

        cout << "Modified Array: ";
        for (int i = 0; i < argc - 1; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Please provide arguments.\n";
    }

    return 0;
}
