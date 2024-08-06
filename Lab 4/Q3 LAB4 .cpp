#include<iostream>
using namespace std;
template<class N>
class doublylinkedlist;
template<typename N>
class node {
	template<class N> friend class circulardoublylinkedlist;
	N data;
	node* next, * prev;

};
template<class N>
class circulardoublylinkedlist {
	node<N>* head;
public:
	circulardoublylinkedlist() {
		head = nullptr;
	}
	~circulardoublylinkedlist() {
		while (head != nullptr) {
			node<N>* curr = head;
			head = curr->next;
			delete curr;
			curr = head;
		}
	}
	void insertatstart(N const val) {
		node<N>* temp = new node;
		temp->data = val;
		temp->next = head;
		head = temp;
	}
	void insertatend(N const val) {
		if (head == nullptr) {
			insertatstart(val);
		}
		node<N>* temp = new node<N>;
		temp->data = val;
		temp->next = nullptr;
		node<N>* curr = head;
		while (curr != nullptr) {
			temp->prev = curr;
			curr = curr->next;
		}
		if (temp->prev == 0) {
			head = temp;
		}
		else {
			temp->prev->next = temp;
		}
	}
	void deletefromstart() {

		node<N>* curr = head;
		head = curr->next;
		delete curr;
		curr = 0;



	}
	void deletefromend() {

		if (head == 0)
		{
			cout << "list is empty\n";
		}
		else {
			node<N>* curr = head;
			while (curr->next != nullptr) {
				curr = curr->next;
			}
			if (curr->prev == nullptr) {
				head = nullptr;

				cout << "Last block deleted" << endl;
			}
			else {
				curr->prev->next = nullptr;
				cout << "Last block deleted" << endl;

			}
		}
	}

	
	void display() const {
		node<N>* curr = head;
		while (curr != nullptr) {
			cout << curr->prev << " ";
			curr = curr->next;
		}
	}
	bool iscircular() {
		if (head == NULL)
		{
			return false;
		}
		node<N>* curr = head;
		do
		{
			curr = curr->next;
		} while (curr != head);
		if (curr == head)
			return true;
		return false;

	}
};
int main() {
	circulardoublylinkedlist<int> l1;
	l1.insertatstart(6);
	l1.insertatstart(8);
	l1.insertatstart(7);
	l1.insertatend(8);
	l1.insertatend(9);
	l1.insertatend(1);
	l1.deletefromend();
	l1.deletefromstart();
	cout << "The linked list is: " << endl;
	l1.display();
	cout << endl;
	l1.iscircular();
	
	system("pause");
}