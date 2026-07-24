#include<bits/stdc++.h>
using namespace std;

int pre(char c){
    if (c == '^') return 2;
    if (c == '*' || c == '/' || c == '%') return 1;
    else return 0;
}

bool as(char c){
    return c=='^';
}

string intopre(string s){
    stack<char> st;
    reverse(s.begin(),s.end());
    string ans;
    for(char c:s){
        if (isalnum(c)){
            ans+= c;
        }
        else if (c == ')'){
            st.push(c);

        }
        else if(c == '('){
            while(st.top() != ')'){
                ans+= st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() &&
            (pre(c)<pre(st.top()) || (pre(c) == pre(st.top()) && as(c)))){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }


    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main(){
    string infix;
    cin>>infix;
    cout<<endl;
    string pre = intopre(infix);
    reverse(pre.begin(),pre.end());
    cout<<pre<<endl;
    return 0;
}