#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int sum = 0;
	int a = 0, b = 1;

	for (int i = 0;i < n - 2;i++) {
		sum = a + b;
		a = b;
		b = sum;
	}

	cout << a + b;
}
