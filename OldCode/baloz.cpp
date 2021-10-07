#include <bits/stdc++.h>

using namespace std;

int a[1000], f[1000][1000], n, w, Max = 0, x, y;

bool cmp (int a, int b)
{
	return a > b;
}

int main(int argc, char const *argv[])
{
	freopen("daydx.inp","r",stdin);
	freopen("daydx.out","w",stdout);
	cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n + 1; i++) 
	{
		f[i][i] = a[i];
		f[0][i] = a[i];
		f[i][0] = a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) 
			if (i != j && f[i][j - 1] + f[0][j] <= w) f[i][j] = f[i][j - 1] + f[0][j];
		    else if (i != j && f[i][j - 1] + f[0][j] > w) f[i][j] = f[i][j - 1];
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++) 
		{
			if (f[i][j] > Max && f[i][j] <= w) 
			{
				x = i;
				y = j;
				Max = f[i][j];
			}
			//cout << f[i][j] << " ";
		}
		//cout << endl;
	}
	cout << Max << endl;
	while (Max > 0)
	{
		if (f[x][y] == f[x][y - 1]) y--;
		else
		{
			cout << f[0][y] << " ";
			Max -= f[0][y];
			y--;
		}
		if (y == 0)
		{
			cout << f[0][x];
			break;
		}
	}
	return 0;
}