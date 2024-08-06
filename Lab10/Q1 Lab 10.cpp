#include<iostream>
using namespace std;
class maxheap {
	int* arr;
	int capacity;
	int size;
public:
	maxheap() {
		arr = nullptr;
		capacity = 0;
		size = 0;
	}
	maxheap(int cap) {
		capacity = cap;
		arr = new int[capacity];
		size = 0;
	}
	bool checkmaxheap(int arr[], int i, int n) {
		if (i >= (n - 1) / 2) {
			return true;
		}
		if (arr[i] >= arr[2 * i + 1] && arr[i] >= arr[2 * i + 2] && checkmaxheap(arr, 2 * i, n) && checkmaxheap(arr, 2 * i + 2, n)) {
			return true;
		}
		return false;

	}
	void swap(int* a, int* b) {
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}
	void heapify(int arr[], int n, int i) {
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l<n && arr[l]>arr[largest]) {
			largest = l;
		}
		if (r<n && arr[r]>arr[largest]) {
			largest = r;
		}
		if (largest != i) {
			swap(&arr[i], &arr[largest]);
			heapify(arr, n, largest);
		}
	}
	void mergeHeaps(int merged[], int x[], int y[], int n,int m)
	{
		for (int i = 0; i < n; i++)
			merged[i] = x[i];
		for (int i = 0; i < m; i++)
			merged[n + i] = y[i];

		buildheap(merged, n + m);
	}

	void buildheap(int arr[], int n) {
		int  start = (n / 2) - 1;
		for (int i = start; i >= 0; i--) {
			heapify(arr, n, i);
		}
	}
	void insert(int k, int value) {
		if (k <= capacity) {
			arr[k] = value;
			size++;
		}
		else {
			capacity = capacity * 2;
			int* temp = arr;
			arr = new int[capacity];
			arr = temp;
			insert(k, value);
		}
		heapify(arr, k- 1, k);
	}
	void print(int arr[], int n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
			cout << endl;
		}

	}
	bool isempty() {
		if (arr = nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	int getmax(int& value) {
		if (!isempty()) {
			value = arr[1];
		}
	}
	void getkthmax(int k) {
		int kt= 0;
		if (arr != nullptr || k < capacity) {
			for (int i = 0; i <= k; i++) {
				kt = arr[k];
			}
			cout << "Max at this index is " << kt;
		}
		else {
			cout << "The value does not exist;";
		}


	}
	void possibleswaps() {

	}
	~maxheap() {
		delete arr[];
			arr = nullptr;
	}

};
int main() {
	maxheap h;
	int c;
	c = 6;
	h.insert(c,12);
	h.insert(c,10);
	h.insert(c,13);
	h.insert(c,23);
	h.insert(c,24);
	h.insert(c,19);
	h.getmax(2);
	h.print();
	h.getkthmax();
	h.possibleswaps();
	h.mergeHeaps();
	system("pause");

}