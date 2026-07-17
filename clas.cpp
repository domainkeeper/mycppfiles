#include<iostream>
using namespace std;


class student{
    public:
        string name;
        int roll;
    student(string name, int roll){
        this->name = name;
        this->roll = roll;

    }
};
int main(){
    string name;
    cin>>name;
    student s1(name, 1234);
    return 0;
}