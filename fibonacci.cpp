#include<iostream>
using namespace std;

void fibonacci(int n);

int main() {
    int n;
    cin >> n;

    fibonacci(n);
    return 0;
}

void fibonacci(int n) {
    cout << "Calculating fibonacci(" << n << ")" << endl;
    int a,b, c;
    a=0;
    b=1;
    for(int c=0;c<=n;){
        
        a=b;
        b=c;
        c=a+b;
        cout << b << " ";
        
    }
}

