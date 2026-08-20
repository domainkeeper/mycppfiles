#include <iostream>
#include <stdexcept>
using namespace std;

class error : public runtime_error {
public:
    using runtime_error::runtime_error;
};


class max_queue{
    private:
        int *arr;
        int rear;
        int size;
    public:
    max_queue(int n){
        size = n;
        rear = -1;
        arr = new int[size];
    }

    bool isempty(){
        return rear == -1;
    }
    bool isfull(){
        return rear==size-1;
    }
    void enqueue(int x){
        if(isfull()){
            cout<<"Overflow"<<endl;
            return;
        }
        int i = rear;
        while(i>-1 && arr[i]>x){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i] = x;
        rear++;
        cout<<"The value inserted is "<<x<<endl;
    }
    int dequeue(){
        if(isempty()){
            cout<<"Underflow";
            throw error("Queue is Empty");

        }
        int i = arr[rear];
        rear --;
        return i;
    }

    int peek(){
        if(isempty()){
            cout<<"underflow"<<endl;
            throw error("Queue is empty.");
        }
        return arr[rear];
    }

    void display(){
        if(isempty()){
            cout<<"Underflow"<<endl;
            return ;
        }
        for (int i=rear;i>-1;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


}
int main(){
    int n,choice,val;
    cout<<"Enter the size: ";
    cin>>n;
    max_queue q(n);
    do{
        
    }

}