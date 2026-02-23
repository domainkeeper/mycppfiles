// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void bubblesort(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j]< arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
            
        }
        
    }
}
void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
    
int main() {
    int n=5;
    int arr[]={4,1,5,3,2};

    bubblesort(arr,n);
    printArray(arr,n);
    return 0;
}