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
	void inorder(TreeNode* t) {
		if (t != 0) {
			inorder(t->left);
			cout << t->data << " ";
			inorder(t->right);
		}
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
	}
public:
	BST() {
		root = nullptr;
	}
	~BST() {}
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
	bool remove(int val)
	{
		TreeNode* curr = root, * parent = 0;
		while (curr != 0 && curr->data != val)
		{
			parent = curr;
			if (val < curr->data)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (curr == 0)
			return false;
		else
		{
			if (curr->left != 0 && curr->right != 0)
			{
				TreeNode* l = curr->left, * pl = curr;
				while (l->right != 0)
				{
					pl = l;
					l = l->right;
				}
				curr->data = l->data;
				curr = l;
				parent = pl;
			}
			TreeNode* child;
			if (curr->left != 0)
			{
				child = curr->left;
			}
			else
			{
				child = curr->right;
			}
			if (curr == root)
			{
				root = child;
			}
			else
			{
				if (curr == parent->left)
					parent->left = child;
				else
					parent->right = child;
			}
			delete curr;
			curr = 0;
			return true;
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
	cout << "Tree's data after removal of a value:";
	b1.remove(2);
	b1.inorder();
	cout << endl;
	system("pause");

}