#include <iostream>
using namespace std;

class calc{
    public:
    calc(int a,float b){
        cout<<a<<b;
    }

    calc(float a,int b){
        cout<<a<<b;
    }
};

int main(){
    calc s(4,6.0);
    return 0;
}

