#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    while (!q.empty()){
        node* curr = q.front();
        if(!curr){
            continue;
        }
        q.pop();
        cout<<curr->data;
        q.push(curr->left);
        q.push(curr->right);
    }
}
void pre(node* root){
    if (!root) return;
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

void in(node* root){
    if (!root) return;
    in(root->left);
    cout<<root->data<<" ";
    in(root->right);
}
void post(node* root){
    if (!root) return;
    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}

node* createTree(){
    int v;
    cin>>v;
    if(v==-1) return nullptr;
    node* newNode = new node(v);
    cout<<"Value of left child of "<<v<<": ";
    newNode->left = createTree();
    cout<<"Value of right child of "<<v<<": ";
    newNode->right = createTree();
    return newNode;
}

int main(){

    cout<<"Enter Root node value: ";
    node* root = createTree();
    pre(root);
    levelorder(root);
}
