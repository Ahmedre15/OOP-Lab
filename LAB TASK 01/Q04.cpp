#include<iostream>
#include <cstdio>
using namespace std;
int main(){
	double weightkg, weightlbs;
	cout << "Enter the weight in kilograms: ";
    cin >> weightkg;
	weightlbs = weightkg * 2.2;
    printf("Weight in kilograms: %.2f kg\n", weightkg);
    printf("Weight in pounds: %.2f lbs\n", weightlbs);
	    return 0;
}