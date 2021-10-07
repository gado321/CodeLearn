#include <bits/stdc++.h>

using namespace std;

float s, n;

float sum(float i)
{
	if (i == 1) return 0;
	if ((int)(i) % 2 == 0) return 1/i + sum(i - 1);
	else return sum(i - 1);
}

int main(int argc, char const *argv[])
{
	cin >> n;
	cout << sum(n * 2);
	return 0;
}