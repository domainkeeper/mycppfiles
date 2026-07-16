#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insert(Node *head,int value, int pos){
    Node* newNode = new Node(value);
    newNode->data=value;
    newNode->next= NULL;
    
    if (pos == 1){
        newNode->next=head;
        head = newNode;
        return;
    }

    Node* temp= head;

    for (int i = 1; i < pos-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    
    if (temp == NULL){
        cout<<"Invalid Position";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

}

void display(Node *head){
    while(head != NULL){
        cout <<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    display(head);
    insert(head,25,2);
    display(head);

    return 0;
}