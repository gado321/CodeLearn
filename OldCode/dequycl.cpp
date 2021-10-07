#include <bits/stdc++.h>

using namespace std;

int n;

float sum(float n)
{
	if (n == 1) return 1;
	else return n + sqrt(sum(n - 1));
}

int main(int argc, char const *argv[])
{
	cin >> n;
	cout << sqrt(sum(n));
	return 0;
}