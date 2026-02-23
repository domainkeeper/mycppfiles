#include<bits/stdc++.h>
using namespace std;

int pattern(int n, int m, int k);
void spaces(int n, int m, int k);

int main(){
    int n;
    cin>>n;

    pattern(n,n,n);
    return 0;

}


int pattern(int n, int m, int k){
    if (n==0) return 0;
    if (n==k&&n==m){
        spaces(n,k,k);
    }
    if (m==0){
        cout<< endl;
        spaces(n-1,k,k);
        pattern(n-1,m=k,k);
        return 0;
    }
    cout << n;
    pattern(n,m-1,k);
}


void spaces(int n, int m, int k){
    if (n==0) return;
    cout << " ";
    spaces(n-1,m,k);
}