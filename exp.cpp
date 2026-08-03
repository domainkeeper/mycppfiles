#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    long long rollNo;
    float marks[3];
    float total;
    float average;

public:
    Student() : rollNo(0), total(0), average(0) {
        for (int i = 0; i < 3; i++) {
            marks[i] = 0;
        }
    }

    void inputData() {
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter roll number: ";
        cin >> rollNo;

        cout << "Enter 3 subject marks:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Mark " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void calculateResult() {
        total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
        average = total / 3;
    }

    void displayData() {
        cout << "\nStudent Record\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nTotal: " << total << endl;
        cout << "Average: " << average << endl;
    }
};

int main() {
    Student s1;

    s1.inputData();
    s1.calculateResult();
    s1.displayData();

    return 0;
}
