#include<iostream>
using namespace std;
template<class N>
class linkedlist;
template<typename N>
class node {
	template<class N> friend class linkedlist;
	N data;
	node* next;
};
template<class N>
class linkedlist {
	node<N>* head;
public:
	linkedlist() {
		head = NULL;
	}
	void sortedInsert(N val) {
		node<N>* temp = new node<N>;
		temp->data = val;
		node<N>* curr = head, * prev = 0;
		while (curr != NULL && curr->data < val) {
			prev = curr;
			curr = curr->next;
		}
		if (prev == 0) {
			head = temp;
		}
		else {
			prev->next = temp;
		}
		temp->next = curr;
	}
	void print() {
		node<N>* curr = head;
		while (curr != nullptr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	void printNth(N index) {
		int count = 1;
		node<N>* curr = head;
		while (curr != nullptr) {
			if (count == index) {
				cout << curr->data << " ";
			}
			count = count++;
			curr = curr->next;
		}
	}
	void deleteatstart() {
		if (head == nullptr) {
			cout << "List is empty";
		}
		else {
			node<N>* curr = head;
			head = curr->next;
			delete curr;
			curr = 0;
			cout << "First block deleted" << endl;
		}
	}
	void deleteatend() {
		if (head == 0) {
			cout << "list is empty" << endl;
		}
		else {
			node<N>* curr = head, * last = 0, * secondlast = 0;
			while (curr != nullptr) {
				secondlast = last;
				last = curr;
				curr = curr->next;
			}
			if (secondlast == 0) {
				head = nullptr;
				delete last;
				last = 0;
				cout << "last block deleted";
			}
			else
			{
				secondlast->next = nullptr;
				delete last;
				last = 0;
				cout << "last block deleted" << endl;
			}
		}
	}
	~linkedlist() {
		while (head != nullptr) {
			node<N>* curr = head;
			head = curr->next;
			delete curr;
			curr = head;
		}
	}
};
int main() {
	linkedlist<int>l1;
	l1.sortedInsert(8);
	l1.sortedInsert(6);
	l1.sortedInsert(10);
	l1.sortedInsert(12);
	l1.sortedInsert(4);
	l1.sortedInsert(3);
	cout << "The following is the sorted linked list: " << endl;
	l1.print();
	cout << endl;
	int x;
	cout << "Enter the index position: " << endl;
	cin >> x;
	cout << "The value at this index is: " << endl;
	l1.printNth(x);
	cout << endl;
	l1.deleteatend();
	l1.deleteatstart();
	system("pause");
}