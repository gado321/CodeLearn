#include <bits/stdc++.h>

using namespace std;

int x, n;

void sum(int n)
{
	cout << n % 10;
	if (n < 10) return;
	else sum(n / 10);
}

int main(int argc, char const *argv[])
{
	cin >> n;
	sum(n);
	return 0;
}