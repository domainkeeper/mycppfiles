#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> salary = {10000,20000,69000,67000,1000000,90000,35000,45000,50000,75000};
    for(auto val:salary){
        cout<<val<<" ";
    }
    cout<<endl;
    int total;
    for(auto val:salary){
        total+=val;
    }
    cout<<total<<endl;
    int high = 0;
    for(auto val:salary){
        if (val > high) high = val;
    }
    cout<<high<<endl;
    int count = 0;
    for(auto val:salary){
        if(val>=50000) count++;
    }
    cout<<count<<endl;
    float avg = total/salary.size();
    cout<<avg<<endl;
    return 0;
}