#include <iostream>
using namespace std;
#include <bits/stdc++.h>

long long sum_even_divisor(int n) {
    long long tmp = 1;
    if (n & 1) {
        for (int i = 1; i <= n; i += 2) tmp *= i;
    }
    else {
        for (int i = 2; i <= n; i += 2) tmp *= i;
    }
    return tmp;
}

int Input() {
	int m;
	cin >> m;
	return m;
}

int main() {
	int n;
	n=Input();
	cout << sum_even_divisor(n);
}