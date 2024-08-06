#include<iostream>
using namespace std;
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int eggdrop(int n, int k) {
	if (k == 1 || k == 0) {
		return k;
	}
	if (n == 1) {
		return k;
	}
	int min = INT_MAX, x, res;
	for (x = 1; x <= k; x++){
		res = max(eggdrop(n - 1, x - 1), eggdrop(n, k - x));
		if (res < min) {
			min = res;
		}

		
	}
	return min + 1;
}
int main() {
	int n, k;
	cout << "Enter no. of eggs "<<endl;
	cin >> n;
	cout << "Enter no. of floors" << endl;;
	cin >> k;
	cout << "Minimum number of attempts that will be taken with " << n << " eggs and " << k << " floor is " << eggdrop(n, k) << endl;
	return 0;


}