#include <bits/stdc++.h>

using namespace std;

int n, m, a[3000][3000], w[3000], f[3000][3000];

void trace(int n, int m)
{
	if (!f[n][m]) return;
	if (f[n][m - 1] == f[n][m]) trace(n, m - 1);
	if (f[n][m - 1] != f[n][m]) trace(n - 1,m - 1), cout << n << " " << m << endl;
}

int main(int argc, char const *argv[])
{
	freopen("hoa.inp","r",stdin);
	freopen("hoa.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	for (int i = 1; i<= m; i++) f[i][i] = a[i][i];
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= n; j++) 
			if (i < j) f[i][j] = max(f[i][j - 1],f[i - 1][j - 1] + a[i][j]);
			else if (i == j) f[i][j] += f[i - 1][j - 1];
	cout << f[m][n] << endl;
	trace(m,n);
	return 0;
}