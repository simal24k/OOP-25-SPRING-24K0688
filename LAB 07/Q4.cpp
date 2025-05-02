#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string a, string p, string e)
        : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayInfo() {
        cout << name << ", " << id << ", " << email << endl;
    }

    void updateInfo(string a, string p, string e) {
        address = a;
        phoneNumber = p;
        email = e;
    }
};

class Student : public Person {
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e, vector<string> c, double g, int y)
        : Person(n, i, a, p, e), coursesEnrolled(c), GPA(g), enrollmentYear(y) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "GPA: " << GPA << ", Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
    vector<string> coursesTaught;
    string department;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e, string d, vector<string> c, double s)
        : Person(n, i, a, p, e), department(d), coursesTaught(c), salary(s) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Dept: " << department << ", Salary: " << salary << endl;
    }
};

class Staff : public Person {
    string department, position;
    double salary;
public:
    Staff(string n, string i, string a, string p, string e, string d, string pos, double s)
        : Person(n, i, a, p, e), department(d), position(pos), salary(s) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Position: " << position << ", Salary: " << salary << endl;
    }
};

class Course {
    string courseId, courseName, instructor;
    int credits;
    string schedule;
public:
    Course(string id, string name, int c, string inst, string sch)
        : courseId(id), courseName(name), credits(c), instructor(inst), schedule(sch) {}

    void registerStudent(Student& s) {
        cout << "Student registered to course: " << courseName << endl;
    }

    double calculateGrades() {
        return 90.0;
    }
};

// selfnotee: tests Inheritance, encapsulation, polymorphism and role-based class behavior in university system.
