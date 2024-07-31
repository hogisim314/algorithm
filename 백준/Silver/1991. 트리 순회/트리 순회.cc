#include <algorithm>
#include <iostream>
#include <deque>
#include <string>
using namespace std;

struct Node {
	char ch;
	Node* left;
	Node* right;

	Node() {
		left = NULL;
		right = NULL;
	};

	Node(char ch) {
		this->ch = ch;
		left = NULL;
		right = NULL;
	}
	~Node() {
		delete left;
		delete right;
	}
};

Node* Tree = new Node[27];

void preorder_traversal(Node* node) {
	if (node == NULL) return;
	cout << node->ch;
	preorder_traversal(node->left);
	preorder_traversal(node->right);
}

void inorder_traversal(Node* node) {
	if (node == NULL) return;
	inorder_traversal(node->left);
	cout << node->ch;
	inorder_traversal(node->right);
	return;
}

void postorder_traversal(Node* node) {
	if (node == NULL) return;
	postorder_traversal(node->left);
	postorder_traversal(node->right);
	cout << node->ch;
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 26; i++) {
		Tree[i].ch = i + 'A';
	}
	for (int i = 1; i <= n; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		if (left != '.') {
			Tree[root - 'A'].left = &Tree[left - 'A'];
		}
		if (right != '.') {
			Tree[root - 'A'].right = &Tree[right - 'A'];
		}
	}
	preorder_traversal(&Tree[0]);
	cout << '\n';
	inorder_traversal(&Tree[0]);
	cout << '\n';
	postorder_traversal(&Tree[0]);
}