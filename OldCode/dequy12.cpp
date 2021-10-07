#include <bits/stdc++.h>

using namespace std;

int x, n;

int pew(int n, int i)
{
	if (i == 0) return 1;
	if (i == 1) return n;
	return n * pew(n, i - 1);
}

int sum(int x, int n)
{
	if (n == 1) return x;
	return pew(x,n) + sum(x, n - 1);
}

int main(int argc, char const *argv[])
{
	cin >> x >> n;
	cout << sum(x,n);
	return 0;
}