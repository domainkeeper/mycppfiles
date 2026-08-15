#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Stack {
private:
    char arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char ch) {
        if (top == 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = ch;
    }

    char pop() {
        if (isEmpty())
            return '\0';

        return arr[top--];
    }

    char peek() {
        if (isEmpty())
            return '\0';

        return arr[top];
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char ch : infix) {

        if (isalnum(ch)) {
            postfix += ch;
        }

        else if (ch == '(') {
            s.push(ch);
        }

        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();

            s.pop();
        }

        else {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.isEmpty())
        postfix += s.pop();

    return postfix;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: "
         << infixToPostfix(infix);

    return 0;
}