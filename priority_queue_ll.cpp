#include <iostream>

class PriorityQueue {
private:
	struct Node {
		int priority;
		int value;
		Node* next;

		Node(int p, int v) : priority(p), value(v), next(nullptr) {}
	};

	Node* head = nullptr;

public:
	PriorityQueue() {
		while (head != nullptr) {
			Node* oldHead = head;
			head = head->next;
			delete oldHead;
		}
	}

	bool empty() const {
		return head == nullptr;
	}

	void push(int priority, int value) {
		Node* newNode = new Node(priority, value);

		if (head == nullptr || priority < head->priority ||
			(priority == head->priority && value < head->value)) {
			newNode->next = head;
			head = newNode;
			return;
		}

		Node* current = head;
		while (current->next != nullptr &&
			   (current->next->priority < priority ||
				(current->next->priority == priority &&
				 current->next->value <= value))) {
			current = current->next;
		}

		newNode->next = current->next;
		current->next = newNode;
	}

	void pop() {
		if (empty()) {
			std::cout << "Priority queue is empty.\n";
			return;
		}

		Node* oldHead = head;
		head = head->next;
		delete oldHead;
	}

	void peek() const {
		if (empty()) {
			std::cout << "Priority queue is empty.\n";
			return;
		}

		std::cout << "Value: " << head->value
				  << ", Priority: " << head->priority << '\n';
	}

	void display() const {
		if (empty()) {
			std::cout << "Priority queue is empty.\n";
			return;
		}

		Node* current = head;
		while (current != nullptr) {
			std::cout << "[Value: " << current->value
					  << ", Priority: " << current->priority << "] ";
			current = current->next;
		}
		std::cout << '\n';
	}
};

int main() {
	PriorityQueue queue;
	int choice;

	do {
		std::cout << "\n1. Insert\n2. Remove\n3. Peek\n4. Display\n5. Exit\n"
					 "Enter choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			int priority, value;
			std::cout << "Enter priority and value: ";
			std::cin >> priority >> value;
			queue.push(priority, value);
			break;
		}
		case 2:
			queue.pop();
			break;
		case 3:
			queue.peek();
			break;
		case 4:
			queue.display();
			break;
		case 5:
			std::cout << "Exiting.\n";
			break;
		default:
			std::cout << "Invalid choice.\n";
		}
	} while (choice != 5);

	return 0;
}
