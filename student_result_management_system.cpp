#include <iostream>
#include <limits>
#include <string>

using namespace std;

class Student {
private:
    int rollNumber{};
    string name;
    double marks{};

public:
    void read() {
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "Roll number: " << rollNumber
             << ", Name: " << name
             << ", Marks: " << marks << '\n';
    }

    double getMarks() const {
        return marks;
    }
};

int main() {
    int count;
    cout << "Enter the number of students: ";
    if (!(cin >> count) || count <= 0) {
        cerr << "The number of students must be positive.\n";
        return 1;
    }

    Student* students = new Student[count];
    for (int i = 0; i < count; ++i) {
        cout << "\nStudent " << i + 1 << '\n';
        students[i].read();
    }

    cout << "\nStudent records:\n";
    for (int i = 0; i < count; ++i) {
        students[i].display();
    }

    Student* topStudent = students;
    for (int i = 1; i < count; ++i) {
        if (students[i].getMarks() > topStudent->getMarks()) {
            topStudent = &students[i];
        }
    }

    cout << "\nStudent with the highest marks:\n";
    topStudent->display();

    delete[] students;
    return 0;
}