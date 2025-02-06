#include <iostream>
#include <string>
using namespace std;

struct Person {
    int id;
    string name;
};

int main() {
    int N;
    cout << "Enter the number of people: ";
    cin >> N;
    Person people[N];

    for (int i = 0; i < N; ++i) {
        cout << "Enter ID for person " << i + 1 << ": ";
        cin >> people[i].id;
        cout << "Enter Name for person " << i + 1 << ": ";
        cin >> people[i].name;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (people[i].id > people[j].id) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    cout << "\nSorted by ID:\n";
    for (int i = 0; i < N; ++i) {
        cout << "ID: " << people[i].id << ", Name: " << people[i].name << endl;
    }
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (people[i].name[0] > people[j].name[0]) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
    cout << "\nSorted by the first character of Name:\n";
    for (int i = 0; i < N; ++i) {
        cout << "ID: " << people[i].id << ", Name: " << people[i].name << endl;
    }
    return 0;
}
