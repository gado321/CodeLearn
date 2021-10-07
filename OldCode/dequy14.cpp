#include <bits/stdc++.h>

using namespace std;

int x, n;

float gt(float i)
{
	if (i == 1) return 1;
	return i * gt(i - 1);
}

float pew(float n, float i)
{
	if (i == 0) return 1;
	if (i == 1) return n;
	return n * pew(n, i - 1);
}

float sum(float x, float i)
{
	if (i == 0) return i;
	return pew(x,i) / gt(i) + sum(x, i - 1);
}

int main(int argc, char const *argv[])
{
	cin >> x >> n;
	cout << sum(x,n);
	return 0;
}