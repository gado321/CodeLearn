#include <bits/stdc++.h>

using namespace std;

int x, n;

long long gt(long long i)
{
	if (i == 1) return 1;
	return i * gt(i - 1);
}

int sum(int i)
{
	if (i == 0) return 0;
	return gt(i) + sum(i - 1); 
}

int main(int argc, char const *argv[])
{
	cin >> n;
	cout << sum(n);
	return 0;
}