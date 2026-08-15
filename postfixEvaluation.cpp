#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }

        return arr[top--];
    }

    int peek() {
        if (isEmpty())
            return -1;

        return arr[top];
    }
};

int calculate(int a, int b, char op) {
    switch (op) {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        return a / b;

    case '^': {
        int result = 1;
        for (int i = 0; i < b; i++)
            result *= a;
        return result;
    }
    }

    return 0;
}

int evaluatePostfix(string expression) {
    Stack s;

    for (char ch : expression) {

        if (isdigit(ch)) {
            s.push(ch - '0');
        }

        else {
            int b = s.pop();
            int a = s.pop();

            int result = calculate(a, b, ch);

            s.push(result);
        }
    }

    return s.pop();
}

int main() {
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result: "
         << evaluatePostfix(postfix);

    return 0;
}