#include<iostream>
using namespace std;
class linkedlist;
struct node {
	friend class linkedlist;
	int data;
	node* next;
};
class linkedlist{
	node* head;
	node* tail;
public:
	linkedlist(){
		head = NULL;
		tail = NULL;
	}
	void insertathead(int val){
		node *temp = new node;
		temp->data = val;
		temp->next = head;
		head = temp;

	}
	void insertattail(int val){
		node *temp = new node;
		temp->data = val;
		temp->next = NULL;
		node *prev = 0, *curr = head;
		while (curr != nullptr){
			prev = curr;
			curr = curr->next;
		}
		if (prev == 0){
			head = temp;
		}
		else{
			prev->next = temp;
		}
	}
	void display(){
		node *curr = head;
		while (curr != nullptr){
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	void eraseathead(){
		node* curr = head;
		head = curr->next;
		delete curr;
		curr = 0;
		cout << "First block deleted" << endl;
	}
	void eraseattail(){
		if (head == 0){
			cout << "list is empty" << endl;
		}
		else{
			node *curr = head, *last = 0, *secondlast = 0;
			while (curr != nullptr){
				secondlast = last;
				last = curr;
				curr = curr->next;
			}
			if (secondlast == 0){
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
				cout    << "last block deleted" << endl;
			}
		}
	}
	~linkedlist(){
		while (head != nullptr){
			node* curr = head;
			head = curr->next;
			delete curr;
			curr = head;
		}
	}
};
int main(){
	linkedlist l1;
	l1.insertathead(2);
	l1.insertathead(6);
	l1.insertathead(7);
	l1.insertattail(3);
	l1.insertattail(8);
	l1.insertattail(1);
	l1.eraseathead();
	l1.eraseattail();
	l1.display();
	system("pause");
}