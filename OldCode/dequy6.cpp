#include <bits/stdc++.h>

using namespace std;

long long s, n;

float sum(float i)
{
	if (i == 1) return 0;
	return 1/(i * (i - 1)) + sum(i - 1);
}

int main(int argc, char const *argv[])
{
	cin >> n;
	cout << sum(n);
	return 0;
}