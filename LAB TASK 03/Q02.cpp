#include <iostream>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }

   
    void displaydate() const {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main() {
 
    Date date(27, 10, 2025);


    cout << "The date is: ";
    date.displaydate();

    return 0;
}