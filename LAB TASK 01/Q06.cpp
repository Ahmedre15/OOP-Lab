#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
    string firstname, lastname;
    float n1, n2, n3, n4, n5;
 cout << "Enter student name followed by five test scores: ";
    cin >> firstname >> lastname;
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    float average = (n1 + n2 + n3 + n4 + n5) / 5;

    cout << "Student name: " << firstname << " " << lastname << endl;
    printf("Test Scores: %.2f %.2f %.2f %.2f %.2f\n", n1, n2, n3, n4, n5);
    printf("Average Score: %.2f\n", average);

    return 0;
}