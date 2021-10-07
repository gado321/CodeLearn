#include <bits/stdc++.h>

using namespace std;

int s, n;

int sum(int i)
{
	if (i == 1) return 1;
	return i + sum(i - 1);
}

int main(int argc, char const *argv[])
{
	cin >> n;
	cout << sum(n);
	return 0;
}