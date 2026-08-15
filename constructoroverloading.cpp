#include<iostream>
using namespace std;

class student{
    private:
    string name;
    int roll;
    int tmarks;

    public:
    student(string n){
        name = n;
        cout << "name constructor"<<endl;
    }
    student( string n , int r){
        name =n;
        roll = r;
        cout<<"name and roll constructor"<<endl;
    }

    student(string n,int r,int m){
        name = n;
        roll = r;
        tmarks = m;
        cout<<"name,roll,marks"<<endl;
    }
};


int main(){
    student s("Pratham");
    student s1("Mayank",9);
    student s3("parth",9,100);
    return 0;
}