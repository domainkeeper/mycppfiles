/*#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int target){
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the target
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int n, target;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    cin >> target;
    cout << linearSearch(arr, n, target) << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int largegstValue(int arr[], int n){
    int m=0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= m) {
            m = arr[i]; 
        }
    }
    return m; 
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>> arr[i];
    }
    cout << largegstValue(arr, n) << endl;
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>> arr[i];
    }
    sort(arr, arr + n);
    int count = 1;
    int f=1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            count++;
        } else {
            if(count > f){
                f = count;
            }
            count = 1;
        }
    }
    if(count > f){
    cout << endl;
    return 0;
}