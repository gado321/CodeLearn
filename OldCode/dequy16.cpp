#include <bits/stdc++.h>

using namespace std;

int x, n;

int sum(int n)
{
	if (n == 0) return 0;
	return 1 + sum(n / 10);
}

int main(int argc, char const *argv[])
{
	cin >> n;
	cout << sum(n);
	return 0;
}