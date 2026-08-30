#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int cap = 10) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool empty() const {
        return size == 0;
    }

    bool full() const {
        return size == capacity;
    }

    int getSize() const {
        return size;
    }

    void enqueue(int value) {
        if (full()) {
            cout << "Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << "Enqueued: " << value << endl;
    }

    int dequeue() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int value = arr[front];
        front = (front + 1) % capacity;
        size--;

        if (empty()) {
            front = 0;
            rear = -1;
        }

        return value;
    }

    int getFront() const {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() const {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    void showStructure() const {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "\nCircular Queue Structure:" << endl;
        cout << "Capacity: " << capacity << ", Size: " << size << endl;
        cout << "Front Index: " << front << ", Rear Index: " << rear << endl;
        cout << "Elements: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            cout << arr[index];
            if (i < size - 1) cout << " -> ";
        }
        cout << " -> " << arr[front] << " (circles back)" << endl << endl;
    }
};

int main() {
    int cap;
    cout << "Enter queue capacity: ";
    cin >> cap;

    Queue q(cap);
    int choice, value;

    cout << "\nCircular Queue using Array\n" << endl;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Show Structure" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "7. Get Size" << endl;
        cout << "8. Get Front" << endl;
        cout << "9. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2: {
                int val = q.dequeue();
                if (val != -1) {
                    cout << "Dequeued: " << val << endl;
                }
                break;
            }

            case 3:
                q.display();
                break;

            case 4:
                q.showStructure();
                break;

            case 5:
                if (q.empty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Queue is not empty" << endl;
                }
                break;

            case 6:
                if (q.full()) {
                    cout << "Queue is full" << endl;
                } else {
                    cout << "Queue is not full" << endl;
                }
                break;

            case 7:
                cout << "Size: " << q.getSize() << endl;
                break;

            case 8: {
                int f = q.getFront();
                if (f != -1) {
                    cout << "Front: " << f << endl;
                }
                break;
            }

            case 9:
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
        cout << endl;
    }

    return 0;
}
