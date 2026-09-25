// Binary tree traversals using a static array representation.
// For a node at index i, its children are at 2*i + 1 and 2*i + 2.

#include <iostream>

constexpr int EMPTY = -1;
constexpr int TREE_SIZE = 15;

int tree[TREE_SIZE] = {
	1, 2, 3, 4, 5, 6, 7,
	8, 9, 10, 11, 12, 13, 14, 15
};

void preorder(int index) {
	if (index >= TREE_SIZE || tree[index] == EMPTY) {
		return;
	}

	std::cout << tree[index] << ' ';
	preorder(2 * index + 1);
	preorder(2 * index + 2);
}

void inorder(int index) {
	if (index >= TREE_SIZE || tree[index] == EMPTY) {
		return;
	}

	inorder(2 * index + 1);
	std::cout << tree[index] << ' ';
	inorder(2 * index + 2);
}

void postorder(int index) {
	if (index >= TREE_SIZE || tree[index] == EMPTY) {
		return;
	}

	postorder(2 * index + 1);
	postorder(2 * index + 2);
	std::cout << tree[index] << ' ';
}

int main() {
	std::cout << "Preorder: ";
	preorder(0);
	std::cout << "\nInorder: ";
	inorder(0);
	std::cout << "\nPostorder: ";
	postorder(0);
	std::cout << '\n';

	return 0;
}
