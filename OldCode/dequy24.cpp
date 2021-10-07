#include <bits/stdc++.h>

using namespace std;

int a[3000][3000],n, x, y, ok[3000][3000], dem, Max = 0;

void dijsktra(int u, int v)
{
	if (a[u][v] == 0) return;
	if (a[u][v] == 1 && ok[u][v] == 0) 
	{
		ok[u][v] = 1;
		dem++;
		dijsktra(u, v - 1);
		dijsktra(u, v + 1);
		dijsktra(u - 1, v);
		dijsktra(u + 1, v);
	}
}

int main(int argc, char const *argv[])
{
	//freopen("daydx.inp","r",stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	cin >> x >> y;
	dijsktra(x,y);
	cout << dem;
	return 0;
}