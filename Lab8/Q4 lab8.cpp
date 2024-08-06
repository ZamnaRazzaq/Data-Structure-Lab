#include<iostream>
using namespace std;
class BST;
class TreeNode {
	friend class BST;
	int data;
	TreeNode* left, * right;
};
class BST {
	TreeNode* root;
	int count = 0;
	void inorder(TreeNode* t) {
		if (t != 0) {
			inorder(t->left);
			cout << t->data << " ";
			inorder(t->right);
		}
	}
	int length(TreeNode* t)
	{
		if (t != 0)
		{
			length(t->left);
			length(t->right);
			count = count + 1;
		}

		return count;
	}
	TreeNode* insert(TreeNode*& t, int val) {
		if (t == 0) {
			t = new TreeNode;
			t->data = val;
			t->left = nullptr;
			t->right = nullptr;
			return t;
		}
		else if (val < t->data) {
			insert(t->left, val);
		}
		else if (val > t->data) {
			insert(t->right, val);
		}
		return t;
	}
public:
	BST() {
		root = nullptr;
	}
	~BST() {}
	void length() {
		int l;
		l = length(root);
		cout << l;
	}
	void inorder() {
		inorder(root);
	}
	bool insert(int val) {
		TreeNode* T = new TreeNode;
		T = insert(root, val);
		if (T == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

};
int main() {
	BST b1;
	b1.insert(6);
	b1.insert(7);
	b1.insert(4);
	b1.insert(2);
	b1.insert(7);
	cout << "Tree's data through In-Order Traversal: ";
	b1.inorder();
	cout << endl;
	cout << "The length of the tree is: ";
	b1.length();
	cout << endl;
	cout << endl;
	system("pause");

}