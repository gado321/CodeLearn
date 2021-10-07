#include <bits/stdc++.h>

using namespace std;

int m, n, a[200][200], f[1000][1000], c[10000];

void xuat(int x, int y)
{
	if (y == 0) return;
	if (f[x][y] - a[x][y] == f[x][y - 1]) xuat(x,y - 1);
	if (f[x][y] - a[x][y] == f[x + 1][y - 1]) xuat(x + 1,y - 1);
	if (f[x][y] - a[x][y] == f[x - 1][y - 1]) xuat(x - 1,y - 1);
	cout << x << " ";
}

int main(int argc, char const *argv[])
{
	freopen("wtoe.inp","r",stdin);
	freopen("wtoe.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	for (int i = 1; i <= n; i++) f[i][1] = a[i][1];
	for (int j = 2; j <= m; j++)
		for (int i = 1; i <= n; i++)
			f[i][j] = max(max(f[i - 1][j - 1],f[i][j - 1]),f[i + 1][j - 1]) + a[i][j];
	int Max = 0, vt = 0;
	for (int i = 1; i <= n; i++)
		if (Max < f[i][m]) Max = f[i][m], vt = i;
	cout << Max << endl;
	xuat(vt,m);
	return 0;
}