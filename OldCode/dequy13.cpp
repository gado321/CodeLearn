#include <bits/stdc++.h>

using namespace std;

float x, n;

float sum(float i)
{
	if (i == 0) return 0;
	return i + sum(i - 1);
}

float pew(float n)
{
	if (n == 1) return 1;
	return 1 / sum(n) + pew(n - 1);
}

int main(int argc, char const *argv[])
{
	cin >> n;
	cout << pew(n);
	return 0;
}