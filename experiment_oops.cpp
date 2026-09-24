#include <iostream>
using namespace std;

class Number {
    int value;

public:
    Number(int v = 0) {
        value = v;
    }

    Number add(Number n) {
        return Number(value + n.value);
    }

    void display() {
        cout << "Result: " << value << endl;
    }
};

Number calculate(Number a, Number b) {
    return a.add(b);
}

int main() {
    Number n1(20);
    Number n2(30);

    Number result = calculate(n1, n2);

    result.display();

    return 0;
}