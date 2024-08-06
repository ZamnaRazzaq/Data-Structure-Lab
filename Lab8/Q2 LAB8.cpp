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
	int c = 0;
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
	TreeNode* kthSmallest(TreeNode* t, int& k)
	{
		if (t == NULL)
			return 0;
		TreeNode* left = kthSmallest(t->left, k);
		if (left != NULL)
			return left;
		count++;
		if (count == k)
			return t;
		return kthSmallest(t->right, k);
	}
	void printKthSmallest(TreeNode* t, int k)
	{


		TreeNode* x = kthSmallest(t, k);
		if (x != nullptr) {
			cout << "Kth smallest element is: " << x->data;
		}
	}
	TreeNode* kthlargest(TreeNode* t, int& k)
	{
		if (t == NULL)
			return 0;
		TreeNode* right = kthlargest(t->right, k);
		if (right!=NULL)
			return right;
		c++;
		if (c == k)
			return t;
		return kthlargest(t->left, k);
	}
	void printkthlargest(TreeNode* t, int k)
	{


		TreeNode* x = kthlargest(t, k);
		if (x != nullptr)
		{
			cout << "Kth largest element is: " << x->data;
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
	void KthSmallest(int k)
	{

		printKthSmallest(root, k);
	}
	void printKthSmallest(int k)
	{
		printKthSmallest(root, k);
	}
	void kthlargest(int k) {
		printkthlargest(root,k);
	}
	void printkthlargest(int k)
	{
		printkthlargest(root, k);
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
	b1.insert(1);
	b1.insert(3);
	b1.insert(5);
	b1.insert(8);
	b1.insert(9);
	b1.insert(10);
	cout << "Tree's data through In-Order Traversal: ";
	b1.inorder();
	cout << endl;
	b1.KthSmallest(7);
	b1.printKthSmallest(7);
	cout << endl;
	b1.kthlargest(3);
	b1.printkthlargest(3);
	system("pause");

}