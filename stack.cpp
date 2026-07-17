#include<iostream>
using namespace std;


class stack{
    public:
        int n;
        int top = -1;
        int *arr;

        stack(int n){
            this->n = n;
            arr = new int[n];
        }
        bool isEmpty(){
            return top == -1;
        
        }

        bool isFull(){
            return top == n - 1;
        }

        void push(int val){
            if(isFull()){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                arr[++top]=val;
            }
        }

        int pop(){
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            else{
                int val=arr[top--];
                return val;
            }
        }

        int peek(){
            if(isEmpty()){
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            else{
                return arr[top];
            }
        }

        void display(){
            if(isEmpty()){
                cout<<"Stack is Empty"<<endl;
            }
            else{
                for(int i=top;i>=0;i--){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }

};

int main(){
    int n;
    cout<<"Enter the size of stack: ";
    cin>>n;
    stack s(n);
    // s.push(33);
    // s.push(47);
    // s.push(78);
    // s.display();
    // cout<<"Top element is: "<<s.peek()<<endl;
    // cout<<"Popped element is: "<<s.pop()<<endl;
    // s.display();
    int n;
    cout<<"No. of operations u can do: ";
    cin>>n;

    for(int i=0;i<n;i++){
        int ch;
        cout<<"Enter your choice: 1.Push 2.Pop 3.Peek 4.Display"<<endl;
        cin>>ch;
        switch (ch){
            case 1:
                int val;
                cin>>val;
                s.push(val);
                break;
            case 2:
                cout<<"Popped element is: "<<s.pop()<<endl;
                break;
            case 3:
                cout<<"Top element is: "<<s.peek()<<endl;
                break;
            case 4:
                s.display();
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
