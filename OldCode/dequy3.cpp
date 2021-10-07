#include <bits/stdc++.h>

using namespace std;

float s, n;

float sum(float i)
{
	if (i == 1) return 1;
	return 1/i + sum(i - 1);
}

int main(int argc, char const *argv[])
{
	cin >> n;
	cout << sum(n);
	return 0;
}