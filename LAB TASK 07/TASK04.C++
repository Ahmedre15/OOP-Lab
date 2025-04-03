#include <iostream>
#include <cstring>
using namespace std;
class Person {
protected:
    char name[50], address[100], phoneNumber[15], email[50];
    int id;

public:
    Person(int pid, const char* pname, const char* paddress, const char* pphone, const char* pemail) {
        id = pid;
        strcpy(name, pname);
        strcpy(address, paddress);
        strcpy(phoneNumber, pphone);
        strcpy(email, pemail);
    }

    virtual void displayInfo() {
        cout << "ID: " << id << "\nName: " << name << "\nAddress: " << address
             << "\nPhone: " << phoneNumber << "\nEmail: " << email << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
private:
    char coursesEnrolled[3][20]; 
    double GPA;
    int enrollmentYear;

public:
    Student(int id, const char* name, const char* address, const char* phone, const char* email, int year, double gpa)
        : Person(id, name, address, phone, email) {
        enrollmentYear = year;
        GPA = gpa;
    }

    void enrollCourse(const char* course) {
        static int count = 0;
        if (count < 3) {
            strcpy(coursesEnrolled[count], course);
            count++;
        } else {
            cout << "Maximum courses reached!\n";
        }
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Enrollment Year: " << enrollmentYear << "\nGPA: " << GPA << "\nCourses Enrolled: ";
        for (int i = 0; i < 3; i++) {
            if (strlen(coursesEnrolled[i]) > 0) cout << coursesEnrolled[i] << " ";
        }
        cout << "\n";
    }
};

class Professor : public Person {
private:
    char department[50], coursesTaught[3][20];
    double salary;

public:
    Professor(int id, const char* name, const char* address, const char* phone, const char* email, const char* dept, double sal)
        : Person(id, name, address, phone, email) {
        strcpy(department, dept);
        salary = sal;
    }

    void assignCourse(const char* course) {
        static int count = 0;
        if (count < 3) {
            strcpy(coursesTaught[count], course);
            count++;
        } else {
            cout << "Maximum courses assigned!\n";
        }
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: $" << salary << "\nCourses Taught: ";
        for (int i = 0; i < 3; i++) {
            if (strlen(coursesTaught[i]) > 0) cout << coursesTaught[i] << " ";
        }
        cout <<"\n";
    }
};

class Staff : public Person {
private:
    char department[50], position[50];
    double salary;

public:
    Staff(int id, const char* name, const char* address, const char* phone, const char* email, const char* dept, const char* pos, double sal)
        : Person(id, name, address, phone, email) {
        strcpy(department, dept);
        strcpy(position, pos);
        salary = sal;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: $" << salary << "\n";
    }
};

class Course {
private:
    int courseId;
    char courseName[50], instructor[50], schedule[20];
    int credits;

public:
    Course(int id, const char* name, const char* prof, int creds, const char* sched) {
        courseId = id;
        strcpy(courseName, name);
        strcpy(instructor, prof);
        credits = creds;
        strcpy(schedule, sched);
    }

    void displayCourseInfo() {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName << "\nInstructor: " << instructor
             << "\nCredits: " << credits << "\nSchedule: " << schedule << "\n";
    }
};

int main() {
    Student s1(101, "Talha Mirza", "D Chowk, Lahore", "0300-1234567", "talha@uni.edu", 2023, 3.7);
    Professor p1(201, "Moonis", "Sadar, Karachi", "0345-0000000", "moonis@uni.edu", "Computer Science", 150000);
    Staff staff1(301, "Izaan Khan", "ABC Road, Islamabad", "0321-0000000", "izaan@uni.edu", "Administration", "Manager", 70000);

    Course c1(501, "Object-Oriented Programming", "Moonis", 3, "MWF 10:00 AM");

    s1.enrollCourse("OOP");
    p1.assignCourse("OOP");

    cout << "\n[University Members]\n";
    s1.displayInfo();
    cout << "\n";
    p1.displayInfo();
    cout << "\n";
    staff1.displayInfo();
    cout << "\n";

    cout << "[Course Details]\n";
    c1.displayCourseInfo();
 
    return 0;
}
