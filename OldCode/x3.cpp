#include <bits/stdc++.h>

using namespace std;

int n, a[1000005];

void np(int n)
{
	if (n)
	{
		int tmp = n % 2;
		n /= 2;
		np(n);
		c.push_back(tmp);
	}
}

int main(int argc, char const *argv[])
{
	freopen("x3.inp","r",stdin);
	//freopen("x3.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d%d",&a[i]);
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 500; j++)
		{
			if ()
		}
	return 0;
}