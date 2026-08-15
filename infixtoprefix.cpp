#include <iostream>
#include <string>
#include <algorithm>
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

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (char &ch : infix) {
        if (ch == '(')
            ch = ')';
        else if (ch == ')')
            ch = '(';
    }

    Stack s;
    string prefix = "";

    for (char ch : infix) {

        if (isalnum(ch)) {
            prefix += ch;
        }

        else if (ch == '(') {
            s.push(ch);
        }

        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                prefix += s.pop();

            s.pop();
        }

        else {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   precedence(s.peek()) > precedence(ch)) {
                prefix += s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.isEmpty())
        prefix += s.pop();

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Prefix expression: "
         << infixToPrefix(infix);

    return 0;
}