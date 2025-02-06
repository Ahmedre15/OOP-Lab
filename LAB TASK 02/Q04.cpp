#include<iostream>
using namespace std;

struct Organisation {
    string organisation_name;
    string organisation_number;

    struct Employee {
        int employee_id;
        string name;
        double salary;
    } emp;
};

int main() {
    Organisation org;

    org.organisation_name = "NU-Fast";
    org.organisation_number = "NUFAST123ABC";
    org.emp.employee_id = 127;
    org.emp.name = "Linus Sebastian";
    org.emp.salary = 400000;
    
    
    
    cout << "The size of structure organisation : " << sizeof(org) << endl;
    cout << "Organisation Name : " << org.organisation_name << endl;
    cout << "Organisation Number : " << org.organisation_number << endl;
    cout << "Employee id : " << org.emp.employee_id << endl;
    cout << "Employee name : " << org.emp.name << endl;
    cout << "Employee Salary : " << org.emp.salary << endl;
    return 0;
}
