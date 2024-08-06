#include <iostream>
using namespace std;
class queue;
class node {
	int data;
	node* next;
	friend queue;
};
class queue{
    node* rear;
    node* front;
    int maxsize;
    int currsize;
    int* arr;
public:
    queue(int n = 10)
    {
        front = rear = 0;
        currsize = 0;
        maxsize = n;
        arr = new int[maxsize];
    }
    int size() {
        node* temp = front;
        int count= 0;
        while (temp != rear->next) {
            count++;
            temp = temp->next;
        }
         return count;

    }
    bool isempty() {
        front == nullptr;
        return front;
    }
    bool First(int& val) {
        if (front = nullptr)
        {
            return 0;
        }
        else {
            node* temp = front;
            while (temp != nullptr);
            {
                if (temp->data == val)
                {
                    return 1;
                }
                temp = temp->next;
            }
        }
    }
    void enqueue(int const& val) {
        node* temp = new node;
        temp->next = nullptr;
        temp->data = val;
        if (rear != nullptr) {
            rear->next = temp;
            rear = temp;
            currsize++;
            temp->next = front;
        }
        else
        {
            rear = temp;
            temp->next = rear;
            front = rear;
            currsize++;
        }
     
    }
    int dequeue() {
        node* curr;
        if (front == nullptr)
        {
            return 0;
        }
        else {
            curr = front;
            front = front->next;
            delete curr;
            curr = 0;
        }
        if (front == nullptr) {
            rear = nullptr;
            return 1;
        }


    }
    void display() {
        
           node* temp = front;
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != nullptr);
        }
   
   
    
    
     
       
};


int main() {
   
    queue* q= new queue;
    q->enqueue(8);
    q->enqueue(2);
    q->enqueue(9);
    q->enqueue(1);
    q->enqueue(7);
    q->enqueue(4);
    cout << "The list is as follow :" << endl;
    q->display();
    q->dequeue();
    cout << "The list is as follow after deleting :" << endl;
    q->display();
   //cout << "IS VALUE THERE OR NOT: " << q->First(1);
    cout << endl;
   

    return 0;

}