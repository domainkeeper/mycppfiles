#include<bits/stdc++.h>
using namespace std;

void pattern(int n, int m, int k);
void spaces(int n, int m, int k);

int main(){
    int n;
    cin>>n;

    pattern(n,n,n);
    return 0;

}


void pattern(int n, int m, int k){
    if (n==0) return ;
    if (n==k&&n==m){
        spaces(n,k,k);
    }
    if (m==0){
        cout<< endl;
        spaces(n-1,k,k);
        pattern(n-1,m=k,k);
        return ;
    }
    cout << n;
    pattern(n,m-1,k);
}


void spaces(int n, int m, int k){
    if (n==0) return;
    cout << " ";
    spaces(n-1,m,k);
}