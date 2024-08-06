#include<iostream>
using namespace std;
template<class k, class v>
class minheap;
template<typename k, typename v>
struct HeapItem
{
	k key;
	v value;
	template<class k, class v> friend class minheap;
};
template<typename k, typename v>
class minheap {
	int capacity;
	int totalitems;
	HeapItem<v> *arr;
public:
	minheap() {
		arr = nullptr;
		totalitems = 0;
		capacity = 0;
	}
	minheap(int cap) {
		capacity = cap;
		arr = new int[cap];
		totalitems = 0;
	}
	~minheap() {
	}
	void swap(int* x, int* y)
	{
		int temp = *y;
		*y = *x;
		*x = temp;
	}
	void insert(k key,v value)
	{
		if (totalitems == capacity)
		{
			capacity = capacity * 2;
			int* x = arr;
			arr = x;
			insert(key,value)
		}
		else {
			arr[key] = value;
			totalitems++;
		}
		Heapify(arr, key);
	}
	void Heapify(int* arr, k key)
	{
		if (key == 0) {
			return;
		}
		else {
			if (arr[key / 2] > arr[key]) {
				swap(arr[key / 2], arr[key]);
				key = key / 2;
			}
			else {
				key = key / 2;
			}
		}
	}
	int deletemin()
	{
		if (totaitems == 1)
		{
			totalitems--;
			return arr[0];
		}
		else {
			int key = arr[0];
			arr[0] = arr[totalitems - 1];
			totalitems--;
			Heapify(0);

			return key;
		}
	}
	bool isEmpty() const {
		if (totalitems == 0) {
			return true;
		}
		else 
			return false;
	}
	int getMin() {
		return arr[0];
	}
	void print() {
		for (int i = 0; i <= capacity; i++) {
			cout << arr[i] << " ";
		}
	}
};

int main() {
	minheap<int,int> h(11);
	int v;
	cout << "Enter values ";
	for (int i = 1; i <= 11; i++)
	{
		cin >> v;
		h.insert(i, v);
	}
	cout << endl;
	cout << "Min heap";
	h.print();
	cout<<endl<<h.getMin();
	h.deletemin();
	system("pause");

}