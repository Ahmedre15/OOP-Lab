#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int id;
public:
    Student(string n, int i) : name(n), id(i) {}
    void displayStudentInfo() {
        cout << "Student ID: " << id << "\nName: " << name << endl;
    }
};

class Marks : public Student {
protected:
    int course1, course2, course3;
public:
    Marks(string n, int i, int c1, int c2, int c3) : Student(n, i), course1(c1), course2(c2), course3(c3) {}
    void displayMarks() {
        cout << "Marks Obtained:\n";
        cout << "PF: " << course1 << "\nOOP: " << course2 << "\nDLD: " << course3 << endl;
    }
};

class Result : public Marks {
public:
    Result(string n, int i, int c1, int c2, int c3) : Marks(n, i, c1, c2, c3) {}
    void displayResult() {
        int total = course1 + course2 + course3;
        float average = total / 3.0;
        cout << "Total Marks: " << total << "\nAverage Marks: " << average << endl;
    }
};

int main() {
    Result student1("Ali", 101, 85, 90, 88);
    
    student1.displayStudentInfo();
    cout << endl;
    student1.displayMarks();
    cout << endl;
    student1.displayResult();
    
    return 0;
}
