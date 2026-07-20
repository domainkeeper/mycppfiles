#include<iostream>
using namespace std;

class ListNode{
    public:
    int val = 0;
    ListNode* next = nullptr;
    ListNode(int val){
        val = val;
        next = nullptr;
    }
};

class stack{
    
    ListNode* top = nullptr;
    public:
    bool isEmpty(){
        return !top;
    }
    void push(int val){
        ListNode* Node = new ListNode(val);
        Node->next = top;
        top = Node;
    }

    int pop(){
        if (isEmpty()){
            cout<<"Stack underflow"<<endl;
            return NULL;
        }else{
            ListNode* temp = top;
            top = top->next;
            int val = temp->val;
            delete temp;
            return val;
        }
    }

    int peek(){
        if (isEmpty()){
            cout<<"Stack underflow"<<endl;
            return NULL;
        }else{
            return top->val;
        }
    }

    void display(){
        if (isEmpty()){
            cout<<"Stack underflow"<<endl;
            return ;
        }else{
            ListNode* temp = top;
            while(temp){
                cout<<temp->val<<"->";
                temp = temp->next;
            }
        }
    }
};

int main(){
    stack s;
    s.push(5);
    s.push(10);
    s.push(20);
    s.peek();
    s.display();
    s.pop();
    s.display();
    return 0;
}