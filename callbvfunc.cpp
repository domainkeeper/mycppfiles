#include <iostream>
using namespace std;

void data(int x){
    x = 50;
    cout<<x<<endl;
}

// void data(int &x){
//     x = 50;
//     cout <<x<<endl;
// }

int main(){
    int ma = 100;
    data(ma);
    cout<<ma;
    return 0;
}