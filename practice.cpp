
#include <bits/stdc++.h>
using namespace std;

class Employee
{
private:
    string namega;
    int age;
    double salary;

public:
    Employee(string n, int a, double s) : name(n), age(a), salary(s) {}

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << ", Salary: " << salary << endl;
    }
};

int main()
{
    Employee emp1("Alice", 30, 50000.0);
    emp1.display();

    Employee emp2("Bob", 25, 45000.0);
    emp2.display(); 

    Employee emp3("Charlie", 28, 48000.0);  
    emp3.display();

    Employee emp4("Diana", 32, 52000.0);
    emp4.display();

    return 0;
}

