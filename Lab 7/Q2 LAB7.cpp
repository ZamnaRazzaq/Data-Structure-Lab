#include<iostream>
using namespace std;
class doublylinkedlist;
struct node{
	char data;
	node* next,*prev;
	friend class doublylinkedlist;
};
class doublylinkedlist{
	node* head,*tail;
public:
	doublylinkedlist(){
		head = nullptr;
		tail = nullptr;
	}
	void insertatstart(char val){
		node* temp = new node;
		temp->data = val;
		if (head == nullptr){
			temp->next = nullptr;
			temp->prev = nullptr;
			head = temp;
			tail = temp;
		}
		else{
			temp->next = head;
			head->prev = temp;
			temp->prev = nullptr;
		}
	}
	bool ispalindrome(node* head,node*tail){
		if (head != tail && head->next != tail){
			if (head->data == tail->data){
				ispalindrome(head->next, tail->prev);
				return true;
			}
			else{
				return false;
			}
		}
		else if(head == tail){
			return true;
		}
		else if (head->next == tail){
			if (head->data == tail->data){
				return true;
			}
			else{ return false; }
		}
		
	}
	node* Head(){
		return head;
	}
	node* Tail(){
		return tail;
	}
	~doublylinkedlist(){
		while (head!=nullptr){
			node* curr = head;
			head = curr->next;
			delete curr;
			curr = head;
	}
	}
};
int main(){
	doublylinkedlist l1;
	l1.insertatstart('m');
	l1.insertatstart('a');
	l1.insertatstart('d');
	l1.insertatstart('a');
	l1.insertatstart('m');
	cout << l1.ispalindrome(l1.Head(),l1.Tail());
	system("pause");
	return 0;
}
