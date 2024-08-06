#include<iostream>
using namespace std;
void merge(int* arr, int l1, int l2, int r1, int r2);
void mergesort(int* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(arr, start, mid);
		mergesort(arr, mid + 1, end);
		merge(arr, start, mid, mid + 1, end);
	}
}
void merge(int* arr, int l1, int l2, int r1, int r2) {
	int* temp = new int[r2 - l1 + 1];
	int i = l1, j = r1, k = 0;
	while (i <= l2 && j <= r2) {
		if (arr[i] < arr[j]) {
			temp[k] = arr[i];
			i++;
		}
		else {
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= l2) {
		temp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= r2) {
		temp[k] = arr[j];
		j++;
		k++;
	}
	int start;
	for (start = l1, k = 0; start <= r2; start++, k++) {
		arr[start] = temp[k];
	}
	delete[] temp;
	temp = 0;
}
int main() {
	int n;
	int max = 0;
	cout << "Enter n to make associations:" << endl;
	cin >> n;
	int* speed = new int[n];
	cout << "Enter the building speed of the wokers: " << endl;
	int size = 2 * n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> speed[i];
	}
	mergesort(speed, 0, size - 1);
	for (int i = size - 1; i >= 1; i = i - 2) {
		max = max + speed[i - 1];
	}
	cout << "the maximum value of the sum of building speeds of all the associations:" << max << endl;
	system("pause");
}

