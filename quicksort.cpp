#include <iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low;j<=high-1;j++){
        if (arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quick(vector<int> &arr,int low, int high){
    if(low>=high) return;
    int pindex = partition(arr,low,high);
    quick(arr,low,pindex-1);
    quick(arr,pindex+1,high);
}

int main(){
    int n;
    cout<<"Enter size"<<endl;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0;i<n;i++){
        cin>>arr[i];
    }
    quick(arr,0,n-1);
}