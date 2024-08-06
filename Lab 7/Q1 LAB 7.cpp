#include<iostream>
using namespace std;
class stack;
class node{
	friend class stack;
	int data;
	node* next;		
};
class stack{
	node* top;
	int maxsize;
	int currsize;
	int*arr;
public:
	stack(int n = 10){
		top = nullptr;
		maxsize = n;
		currsize = 0;
	}
	bool isempty(){
		if (top == 0){
			return 1;
		}
		return 0;
	}
	bool isfull(int val){
		if (currsize == maxsize){
			return 1;
		}
		return 0;
	}
	bool push(int val){
		node* temp = new node;
		temp->data = val;
		if (top == 0){
			top = temp;
			top->next = nullptr;
		}
		else {
			temp->next = top;
			top = temp;
		}

	}
	bool pop(){
		if (isempty()){
			return false;
		}
		else{
			int x;
			x = top->data;
			node*temp = top;
			top = top->next;
			delete temp;
			temp = 0;
			return x;
			
		}
	}
	void sort(int val, int val2){
		if (isempty(val) || val2>top(val))){
			push(val);
			return;

		}
		int temp = pop(val);
		sort(val);
		push(temp);
	}
	void sortstack(node* n){
		if (!isempty()){
			int x = pop(n);
			sortstack(n);
			sort(n,x)
		}
	}

	void reverse(){

	}
};

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		





































































































































































































































