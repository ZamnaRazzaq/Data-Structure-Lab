#include<iostream>
using namespace std;
template< class T>
void Swap(T x, T y){
	T temp = x;
	x = y;
	y = temp;
	cout << "First value: " << x << " " << "Second Value:" << y << endl;

}

int main(){

	int i1 = 6;
	int i2 = 3;
	float f1 = 7.2;
	float f2 = 4.5;
	char c1 = 'p';
	char c2 = 'x';
	cout << "Before Swapping " << endl;
	cout << "First value: " << i1 << " " << " Second value: " << i2;
	cout << endl;
	cout << "After swaping " << endl;
	Swap(i1, i2);
	cout << endl;
	cout << "Before Swapping " << endl;
	cout << "First value: " << f1 << " " << " Second value: " << f2;
	cout << endl;
	cout << "After swaping " << endl;
	Swap(f1, f2);
	cout << endl;
	cout << "Before Swapping " << endl;
	cout << "First value: " << c1 << " " << " Second value: " << c2;
	cout << endl;
	cout << "After swaping " << endl;
	Swap(c1, c2);
	system("pause");

}