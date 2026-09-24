#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    class Address {
    private:
        string city;
        string state;

    public:
        Address(string city = "Not specified", string state = "Not specified")
            : city(city), state(state) {}

        void displayAddress() const {
            cout << "Address: " << city << ", " << state << endl;
        }
    };

private:
    long long rollNo;
    string name;
    double cgpa;
    Address address;

public:
    Student(long long rollNo, string name)
        : rollNo(rollNo), name(name), cgpa(0.0) {}

    Student(long long rollNo, string name, double cgpa)
        : rollNo(rollNo), name(name), cgpa(cgpa) {}

    void updateCGPA(double cgpa) {
        this->cgpa = cgpa;
    }

    void setAddress(string city, string state) {
        address = Address(city, state);
    }

    void displayInfo() const {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
        address.displayAddress();
        cout << endl;
    }
};

int main() {
    Student students[5] = {
        Student(101, "Aarav"),
        Student(102, "Diya", 8.4),
        Student(103, "Kabir"),
        Student(104, "Meera", 9.1),
        Student(105, "Rohan")
    };

    students[0].setAddress("Delhi", "Delhi");
    students[1].setAddress("Mumbai", "Maharashtra");
    students[2].setAddress("Bengaluru", "Karnataka");
    students[3].setAddress("Chennai", "Tamil Nadu");
    students[4].setAddress("Kolkata", "West Bengal");

    students[0].updateCGPA(7.8);
    students[2].updateCGPA(8.7);
    students[4].updateCGPA(9.0);

    for (const Student& student : students) {
        student.displayInfo();
    }

    return 0;
}