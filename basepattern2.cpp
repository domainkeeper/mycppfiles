#include<bits/stdc++.h>
using namespace std;

void pattern(int n, int m, int k);
void spaces(int n, int m, int k);

char a='a';

int main(){
    int n;
    cin>>n;

    pattern(n,n,n);
    return 0;

}

void pattern(int n, int m, int k){
    if (n==0) return ;
    if (m==0){
        cout << endl;
        spaces(n-1,k,k-n+1);
        pattern(n-1,m=n-1,k);
        return ;
    }
    cout << a << " ";
    a++;
    pattern(n,m-1,k);

}

void spaces(int n, int m, int k){
    if (k==0) return;
    cout << " ";
    spaces(n-1,m,k-1);
}




