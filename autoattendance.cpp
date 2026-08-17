#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<double> att = {75.6,88.9,99.44,66.98,24.08,78.90};
    for (auto val:att){
        cout<<val<<" ";
    }
    cout<<endl;
    for(auto val:att){
        if (val>=75) cout<<val<<" ";
    }
    return 0;
}