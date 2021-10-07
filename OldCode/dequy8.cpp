#include <bits/stdc++.h>

using namespace std;

float s, n;

float sum(float i)
{
	if (i == 0) return 1/2;
	return (i + 1)/(i + 2) + sum(i - 2);
}

int main(int argc, char const *argv[])
{
	cin >> n;
	cout << sum(n * 2);
	return 0;
}