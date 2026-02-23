#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int num;
    cin>>num;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            cout<<"Found at index "<<i<<endl;
            return 0;
        }
        
    }
    cout<<"Not found"<<endl;
    return 0;
    
}