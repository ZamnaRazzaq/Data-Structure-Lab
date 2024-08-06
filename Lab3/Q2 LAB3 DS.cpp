#include<iostream>
using namespace std;
class linkedlist;
struct node {
	friend class linkedlist;
	int data;
	node* next;
};
class linkedlist {
	node* head;
public:
	linkedlist() {
		head = NULL;
	}
	void insertathead(int val) {
		node* temp = new node;
		temp->data = val;
		temp->next = head;
		head = temp;

	}
	void display() {
		node* curr = head;
		while (curr != nullptr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	linkedlist Union(linkedlist& A) {
		int x;
		node* curr = A.head;
		linkedlist product;
		while (curr != nullptr) {
			x = curr->data;
			product.insertathead(x);
			curr = curr->next;

		}
		curr = nullptr;
		curr = this->head;
		while (curr != nullptr) {
			x = curr->data;
			product.insertathead(x);
			curr = curr->next;
		}
		return product;
	}
	linkedlist intersection(linkedlist& A) {
		linkedlist product;
		node* curr = this->head;
		while (curr != nullptr) {
			node* temp = A.head;
			while (temp != nullptr) {
				if (curr->data == temp->data) {
					product.insertathead(curr->data);
				}
				temp = temp->next;
			}
			curr = curr->next;
		}
		return product;
	}
	void sorted(int val) {
		node* curr = new node;
		curr->data = val;
		curr->next = head;
		head = curr;
		node* index = nullptr;
		int t;
		if (head == nullptr) {
			cout << "List is empty" << endl;
		}
		else {
			index = curr->next;
		}
		while (index !=nullptr){
			if (curr->data > index->data) {
				t = curr->data;
				curr->data = index->data;
				index->data = t;
			}
			index = index->next;
			curr = curr->next;
			}
	}
	
};
int main() {
	linkedlist l1;
	linkedlist l2;
	linkedlist l5;
	l1.insertathead(3);
	l1.insertathead(8);
	l1.insertathead(5);
	l1.insertathead(1);
	l1.insertathead(4);
	l2.insertathead(9);
	l2.insertathead(3);
	l2.insertathead(7);
	l2.insertathead(2);
	l2.insertathead(10);
	l2.insertathead(5);
	l2.insertathead(8);
	l2.insertathead(1);
	l2.insertathead(6);
	l2.insertathead(4);
	cout << "Linked list A " << endl;
	l1.display();
	cout << endl;
	cout << "Linked list B " << endl;
	l2.display();
	cout << endl;
	cout << "Union of the linked lists" << endl;
	linkedlist l3 = l1.Union(l2);
	l3.display();47
	cout << endl;
	cout << "Intersection of two linked lists" << endl;
	linkedlist l4;
	l4 = l1.intersection(l2);
	l4.display();
	cout << endl;
	l5.sorted(6);
	l5.sorted(9);
	l5.sorted(3);
	l5.sorted(4);
	l5.sorted(1);
	l5.sorted(7);
	cout << " Sorted linked list "<<endl;
	l5.display();
	cout << endl;
	system("pause");

}

