#include <iostream>
using namespace std;
template <class T>
bool comparetemp(T x, T y) {
	if (x == y) {
		return true;

	}
}
template <class T>
bool comparetemp(T* x, T* y) {
	if (x == y) {
		return true;

	}
}
template<>
bool comparetemp<const char*>(const char* x, const char* y) {
	for (int i = 0; x[i] != '\0'; i++) {
		if (x[i] == y[i])
			return true;
	}
}


int main()
{
	int x = 'a', y = 97;
	char a = 'a', b = 'a';
	char* aptr = &a, * bptr = &b;
	string str1 = "String", str2 = "String";
	(comparetemp(x, y)) ? cout << "Integers are equal" : cout << "Integers are not e qual";
	cout << endl;
	(comparetemp(a, b)) ? cout << "Chars are equal" : cout << "Chars are not equal";   cout << endl;
	(comparetemp(aptr, bptr)) ? cout << "Pointers are equal" : cout << "Pointers are  not equal";
	cout << endl;
	(comparetemp(str1, str2)) ? cout << "Strings are equal" : cout << "Strings are n ot equal";
	system("pause");

}



 