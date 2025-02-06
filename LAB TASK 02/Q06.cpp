#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Subject {
    string subject_name; 
};
struct Student {
    int ID;                     
    Subject subjects[3];     
};

int main() {
    int n;  
    cout << "Enter the number of students: ";
    cin >> n;
    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        cout << "Enter ID: ";
        cin >> students[i].ID;
        for (int j = 0; j < 3; j++) {
            cout << "Enter subject " << j + 1 << ": ";
            cin >> students[i].subjects[j].subject_name;
        }
    }
    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent ID: " << students[i].ID << endl;
        cout << "Subjects:\n";
        for (int j = 0; j < 3; j++) {
            cout << students[i].subjects[j].subject_name << endl;
        }
    }
    return 0;
}
