#include <bits/stdc++.h>

using namespace std;

int x, n;

int sum(int n, int i)
{
	if (i == 0) return 1;
	if (i == 1) return n;
	return n * sum(n, i - 1);
}

int main(int argc, char const *argv[])
{
	cin >> x >> n;
	cout << sum(x,n);
	return 0;
}