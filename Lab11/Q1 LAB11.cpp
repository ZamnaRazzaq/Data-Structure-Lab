#include<iostream>
using namespace std;
class Heap
{
	int size, capacity;
	int* h = 0;
public:
	Heap(int n = 10)
	{
		size = n;
		capacity = 0;
		h = new int[size];
	}
	~Heap()
	{
		if (h != 0)
		{
			delete[] h;
			h = 0;
		}
	}

	void heapify(int i)
	{
		int left, right, largest;
		while (1)
		{
			left = 2 * i, right = 2 * i + 1, largest = i;
			if (left <= capacity && h[left] > h[largest])
				largest = left;
			if (right <= capacity && h[right] > h[largest])
				largest = right;
			if (largest == i)
				break;
			else
			{
				swap(h[i], h[largest]);
				i = largest;
			}
		}
	}

	void buildHeap(int* a, int n)
	{
		if (h != 0)
		{
			delete[] h;
			h = 0;
		}
		h = new int[n + 1];
		size = n;
		for (int i = 0; i < n; i++)
		{
			h[i + 1] = a[i];
		}
		capacity = n;
		for (int i = capacity / 2; i >= 1; i--)
		{
			heapify(i);
		}
	}
	void display()
	{
		for (int i = 0; i < capacity; i++)
		{
			cout << h[i + 1] << " ";
		}
	}
	void removeMax(int & a)
	{
		a = h[1];
		h[1] = h[capacity];
		capacity--;
		heapify(1);
	}

};
void heapSort(int* a, int n)
{
	Heap mh;
	mh.buildHeap(a, n);
	for (int i = n - 1; i >= 0; i--)
	{
		mh.removeMax(a[i]);
	}
}
int main()
{
	int arr[] = { 14, 19, 42, 33, 26, 31, 27, 44, 35, 10 };
	Heap mh;
	mh.buildHeap(arr, 10);
	mh.display();
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	heapSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}