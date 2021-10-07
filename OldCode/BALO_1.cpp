#include <bits/stdc++.h>

using namespace std;

int a[205], f[205][40005], n, w;

void trace(int n, int m)
{
	if (m == 0 || n == 0) return;
	if (f[n][m] == f[n - 1][m]) trace(n - 1,m);
	if (f[n][m] != f[n - 1][m]) 
	{
		trace(n - 1,m - a[n]);
		cout << a[n] << " ";
	}
}

int main(int argc, char const *argv[])
{
	cin >> n >> w;
	for (int i = 1; i<= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= w; j++)
		if (j >= a[i])
			f[i][j] = max(f[i - 1][j],f[i - 1][j - a[i]] + a[i]);
		else f[i][j] = f[i - 1][j];
	if (f[n][w] == w) cout << "YES";
	else cout << "NO";
	//trace(n,w);
	return 0;
}