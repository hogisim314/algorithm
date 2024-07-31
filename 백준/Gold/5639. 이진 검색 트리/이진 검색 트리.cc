#include <iostream>
#include <string>
using namespace std;

int arr[1000011];

struct treeNode {
	int src;
	treeNode* left;
	treeNode* right;

	treeNode() {
		src = 0;
		left = NULL;
		right = NULL;
	}

	treeNode(int src) {
		this->src = src;
		left = NULL;
		right = NULL;
	}
};

void insertNode(treeNode* Node, treeNode* key) {
	if (key->src < Node->src) {
		if (Node->left == NULL) {
			Node->left = key;
			return;
		}
		insertNode(Node->left, key);
	}
	else if (Node->src < key->src) {
		if (Node->right == NULL) {
			Node->right = key;
			return;
		}
		insertNode(Node->right, key);
	}
}

void postOrderTraverse(treeNode* Root) {
	if (Root->left != NULL) {
		postOrderTraverse(Root->left);
	}
	if (Root->right != NULL) {
		postOrderTraverse(Root->right);
	}	
	cout << Root->src << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a = 0;
	int num;
	while (cin>>num) {
		arr[a++] = num;
	}
	treeNode* root = new treeNode(arr[0]);

	for (int i = 1; i < a; i++) {
		insertNode(root, new treeNode(arr[i]));
	}
	postOrderTraverse(root);
}