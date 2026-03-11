#include <iostream>
using namespace std;

int main(){
    int i,j,temp,n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n-1;i++){
        int minIndex = i; // Assume the minimum is the first element
        for(j=i+1;j<n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j; // Update the index of the minimum element
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    cout<<"Sorted array: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}