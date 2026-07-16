#include<iostream>
using namespace std;


class stack{
    public:
        int arr[100];
        int top = -1;

        bool isEmpty(){
            return top == -1;
        
        }

        bool isFull(){
            return top == 99;
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
    stack s;
    s.push(33);
    s.push(47);
    s.push(78);
    s.display();
    cout<<"Top element is: "<<s.peek()<<endl;
    cout<<"Popped element is: "<<s.pop()<<endl;
    s.display();
    return 0;
}
