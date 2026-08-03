#include <iostream>
using namespace std;

inline int add(int a, int b){
    int c = a+b;
    return c;
}

int main(){
    int d = 20;
    int e = 30;
    cout<<add(d,e)<<endl;
    cout<<add(50,60);
    return 0;
}

// void data(string name = "pratham kaushik"){
//     cout<<name<<endl;
// }

// int main(){
//     data();
//     data("domain keeper");
// }