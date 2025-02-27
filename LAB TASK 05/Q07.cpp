#include <iostream>

using namespace std;

class Student {
    const int roll_no;

public:
    Student(int r) : roll_no(r) {}

    void display() {
        cout << "Student Roll No: " << roll_no << endl;
    }
};

int main() {
    int roll;
    cout << "Enter Student Roll No: ";
    cin >> roll;

    Student s(roll);
    s.display();

    return 0;
}
