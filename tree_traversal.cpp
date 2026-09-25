#include<iostream>
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

int main(){
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    pre(root);
    cout<<endl;
    in(root);
    cout<<endl;
    post(root);
}