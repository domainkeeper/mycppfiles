#include<bits/stdc++.h>
using namespace std;

int evaluate(string s){
    stack<int> st;
    for(char c:s){
        if (isdigit(c)){
            st.push(c-'0');
        }
        else{
            int op1,op2;
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            switch(c){
                case '+': st.push(op1+op2);
                case '-': st.push(op1-op2);
                case '*': st.push(op1*op2);
                case '/': st.push(op1/op2);
                case '%': st.push(op1%op2);
                case '^': st.push(pow(op1,op2));
            }
        }
    }
    return st.top();
}
int main(){
    string postfix;
    cin>>postfix;
    cout<<endl<<evaluate(postfix);
    return 0;
}