#include<iostream>
using namespace std;

int main(){
    int numbers[5];
     for (int i = 0; i < 5; i++)
    {
        cout << "Enter Number " << i + 1 << ": "; 
        cin >> numbers[i];

    }
    int sum=0;
    int *ptr = numbers;
      for (int i = 0; i < 5; i++)
    {
        sum=sum+*(ptr+i);

    }
       cout << "The Sum is: " << sum << endl;
    
    return 0;
}