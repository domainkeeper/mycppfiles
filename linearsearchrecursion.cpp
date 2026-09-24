#include <iostream>
#include <vector>
using namespace std;

int lins(vector<int> &arr, int i, int k){
    if(i == arr.size()) return -1;
    if(arr[i] == k) return i;
    return lins(arr,i+1,k);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    cout<<lins(arr,0,3);
}