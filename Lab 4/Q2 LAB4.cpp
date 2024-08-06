#include<iostream>
using namespace std;
template<class N>
class doublylinkedlist;
template<typename N>
class node {
	template<class N> friend class doublylinkedlist;
	N data;
	node* next, * prev;

};
template<class N>
class doublylinkedlist {
	node<N>* head;
public:
	doublylinkedlist() {
		head = nullptr;
	}
	~doublylinkedlist() {
		while (head != nullptr) {
			node<N>* curr = head;
			head = curr->next;
			delete curr;
			curr = head;
		}
	}
	void insertatstart(N const val) {
		node<N>* temp = new node<N>;
		temp->data = val;
		temp->next = head;
		head = temp;
	}
	void insertatend(N const val) {
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
			if (head->next == nullptr) {
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
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	void printRev() const {
		node<N>* curr = head;
		if (curr != nullptr) {
			node<N>* prevnode = curr;
			node<N>* tempnode = curr;
			node<N>* currnode = curr->next;
			tempnode->next = nullptr;
			prevnode->prev = nullptr;
			while (currnode != nullptr) {
				tempnode = currnode->next;
				currnode->next = prevnode;
				prevnode->prev = currnode;
				prevnode = currnode;
				currnode = tempnode;
			}
			curr = prevnode;
		}
		while(curr!=nullptr){
			cout << curr->data << " ";
			curr = curr->next;
		}

	}
};
int main() {
	doublylinkedlist<int> l1;
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
	cout << "The linked list in reverse order: " << endl;
	l1.printRev();
	system("pause");
}