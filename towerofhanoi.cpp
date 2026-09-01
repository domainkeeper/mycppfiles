#include<iostream>
using namespace std;

void towerofhanoi(string A,string B,string C,int n){
    if(n==1){
        cout<<A<<"->"<<C<<endl;
        return;
    }
    towerofhanoi(A,C,B,n-1);
    cout<<A<<"->"<<C<<endl;
    towerofhanoi(B,A,C,n-1);
}

int main(){
    int n;
    cin>>n;
    string A = "A", B = "B" , C = "C";
    cout<<"===Tower of Hanoi===\n";
    towerofhanoi(A,B,C,n);
    return 0;
}