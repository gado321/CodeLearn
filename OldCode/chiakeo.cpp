#include <bits/stdc++.h>

using namespace std;

int a[1000], f[1000][1000], n, w, ans, check[1000];

void trace(int n, int m)
{
	if (!f[n][m]) return;
	if (f[n][m] == f[n - 1][m]) trace(n - 1,m);
	if (f[n][m] != f[n - 1][m]) 
	{
		trace(n - 1, m - a[n]);
		check[n] = 1;
		cout << n << " ";
	}
}

int main(int argc, char const *argv[])
{
	freopen("chiakeo.inp","r",stdin);
	freopen("chiakeo.out","w",stdout);
	cin >> n;
	for (int i = 1; i<= n; i++) cin >> a[i], w += a[i];
	ans = w;
	w /= 2;
	for (int i = 1; i<= n; i++)
		for (int j = 1; j <= w; j++)
			if (j < a[i]) f[i][j] = f[i - 1][j];
			else f[i][j] = max(f[i - 1][j],f[i - 1][j - a[i]] + a[i]);
	cout << ans - f[n][w] * 2 <<  endl;
	//trace(n,w);
	//cout << endl;
	//for (int i = 1; i <= n; i++)
		//if (!check[i]) cout << i << " ";
	return 0;
}