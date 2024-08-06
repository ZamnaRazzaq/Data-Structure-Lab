#include<iostream>
#include<string>
using namespace std;
void merge(string* arr, int l1, int l2, int r1, int r2);
void mergesort(string* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(arr, start, mid);
		mergesort(arr, mid + 1, end);
		merge(arr, start, mid, mid + 1, end);
	}
}
void merge(string* arr, int l1, int l2, int r1, int r2) {
	string* temp = new string[r2 - l1 + 1];
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
	int n, m;
	cout << "Enter no. of teachers";
	cin >> n;
	cout << "Enter no. of students";
	cin >> m;
	string* teacher = new string[n];
	cout << "Enter teachers name: ";
	for (int i = 0; i < n; i++) {
		getline(cin,teacher[i]);
	}
	string* student = new string[m];
	cout << "Enter students name and age: ";
	for (int i = 0; i < m; i++) {
		getline(cin, student[i]);
	}
	int count = 0;
	string* temp = new string[n + m];
	for (int i = 0; i < n; i++) {
		temp[i] = teacher[i];
		count++;
	}
	for (int i = 0; i < m,count<n+m; i++,count++) {
		temp[count] = student[i];
	}
	cout << "Before sorting:";
	for (int i = 0; i < n + m; i++) {
		cout << temp[i] << endl;
	}
	cout << endl;
	cout << "After sorting in lexographical order:";
	 mergesort(temp, 0,(n+m)-1);
	for (int i = 0; i < n+m; i++) {
		cout << temp[i]<<endl;
	}

}