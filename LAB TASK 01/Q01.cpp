#include<iostream>
using namespace std;

int main(){
    float numbers[20];
    float max, secmax;
    for (int i = 0; i < 20; i++)
    {
        cout << "Enter Number " << i + 1 << ": "; 
        cin >> numbers[i];

    }
    float *ptr = numbers;
    if (*ptr > *(ptr + 1)) {
        max = *ptr;
        secmax = *(ptr + 1);
    } else {
        max = *(ptr + 1);
        secmax = *ptr;
    }
     for (int i = 2; i < 20; i++) {
        if (*(ptr + i) > max) {
            secmax = max;
            max = *(ptr + i);
        } else if (*(ptr + i) > secmax && *(ptr + i) != max) {
            secmax = *(ptr + i);
        }
    }

    cout << "The Second Max Number is: " << secmax << endl;
    
    return 0;
}