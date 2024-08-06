#include<iostream>
using namespace std;
class stack;
class node {
	friend stack;
	int data;
	node* next;

};
class stack {
	int maxsize;
	int currsize;
	node* top;
	int* arr;
public:
	stack(int n = 10) {
		maxsize = n;
		currsize = 0;
		top = nullptr;
		arr = new int[maxsize];
	}
	int size() {
		int count = 0;
		node* temp = top;
		if (temp->next != 0) {
			count = count++;
			temp = temp->next;
			cout <<endl<< "The size is : " << count;
		}
		return 0;
	}
	bool isempty() {
		if (currsize == 0)
		{
			return 1;
		}
		return 0;
	}
	void pop() {
		node* curr = top, * last = 0, * secondlast = 0;
		while (curr != nullptr) {
			secondlast = last;
			last = curr;
			curr = curr->next;
		}
		if (secondlast == 0) {
			top = nullptr;
			delete last;
			last = 0;
		}
		else {
			secondlast->next = nullptr;
			delete last;
			last = 0;
		}
	}
	bool push(int& val) {
		node* temp = new node;
		temp->data = val;
		temp->next = nullptr;
		node* prev = 0, * curr = top;
		while (curr != nullptr) {
			prev = curr;
			curr = curr->next;
		}
		if (prev == 0) {
			top = temp;
			return 1;
		}
		else {
			prev->next = temp;
			return 1;
		}
	}
	void display()
	{
		node* curr = top;
		while (curr != nullptr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	stack sort(stack val) {
		stack temp;   // 1
		int x;  //1

		while (!val.isempty()) { //n
			x = val.top->data;  //n
			val.pop(); //n
			if (temp.isempty() && temp.top->data < x) { //1xn
				temp.push(x);
			}
			else { //1xn
				val.push(temp.top->data);
				temp.pop();
			}

		}
		return temp;
		         // time complexity = 4n +2;


	}
  
	void  deletemidvalue(int val)
	{
		int temp;;  //1
		int t;  //1
		temp = val;//1
		if (top == nullptr) {   //1
			return; //1
		}  //1
		else { //1
			if (temp == (val / 2 + 1)) { //1
				pop();
				return;
			}
			else {  //1
				t = top->data;
				pop();
				temp--;
			}
			deletemidvalue(temp);  //1
			push(t);
		}  // time complexity is 1
	}
	bool pallindrome()
	{
		node* temp = top;    //1
		for (int i = 0; i < currsize / 2; i++)       //n/2 +1
		{
			for (int j = 0; j < currsize - i - 1; j++)    // n/2 x n
				top = top->next;
			if (temp->data == top->data)  //1
				cout<<endl << "Palindrome" << endl;
				return 1;
			temp = temp->next;
		}
		cout <<endl<< "Not palindrome";    //1
		return 0;   // time complexity is n^2/2 + n/2 +4
	}
	int sum(int k)
	{
		node* temp = top;    //1
		if (top != nullptr) {    //1
			for (; top != nullptr; top = top->next)    //n
			{
				for (temp = top; temp != NULL; temp = temp->next)    //nxn
				{
					if (top->data + temp->data == k)   //nxn
					{
						cout<<endl<<"The elements are " << top->data << " and " << temp->data << endl;
						return true;
					}
				}
			}
		}
		cout << "there is no sum of two elements which are equal to k " << endl;;  //1
			return false;   
			// timecomplexity is 2n^2 + n +3;
	}

};
int main()
{
	int a = 10;
	int b = 3;
	int c = 4;
	int d = 5;
	int e = 7;
	int f = 12;
	stack s;
s.push(a);
s.push(b);
s.push(c);
s.push(d);
s.push(e);
s.push(f);
cout << "The list is as follow: " << endl;
s.deletemidvalue(4);
s.display();
cout <<endl<< "The list is as follow after deleting mid value: " << endl;
s.display();
s.size();
s.pallindrome();
s.sum(10);


stack s2;
s2.push(a);
s2.push(b);
s2.push(c);
s2.push(d);
s2.push(e);
s2.push(f);
stack sortedlist;
sortedlist = sortedlist.sort(s2);
cout << "Sorted stack is as follow: " << endl;
sortedlist.display();

system("pause");

}