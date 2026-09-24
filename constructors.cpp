#include <iostream>
using namespace std;

class student{
    public:
    const int roll;
    student(int r):roll(r){
        cout<<"Hello\n";
    }
};

int main(){
    student s(1000);
    cout<<s.roll;
}