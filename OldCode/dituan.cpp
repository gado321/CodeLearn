#include <bits/stdc++.h>

using namespace std;

int r[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int c[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int x, y, n, ans = 1, a[50][50];
bool ok[50][50];

void bachtrach(int xx, int yy)
{
	for (int i = 0; i < 8; i++)
	{
		int u = xx + r[i];
		int v = yy + c[i];
		if (u > 0 && v > 0 && u <= n && v <= n && !a[u][v])
		{
			a[u][v] = ++ans;
			if (ans == n * n)
			{
				for (int k = 1; k <= n; k++)
				{
					for (int f = 1; f <= n; f++) cout << a[k][f] << " ";
					cout << "\n";
				}
				exit(0);
			}
			else bachtrach(u,v);
			ans--;
			a[u][v] = 0;
		}
	}
}

int main(int argc, char const *argv[])
{
	cin >> n >> x >> y;
	a[x][y] = 1;
	bachtrach(x,y);
	return 0;
}