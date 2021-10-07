#include <bits/stdc++.h>

using namespace std;

int n, m, val[3000], w[3000], f[3000][3000];

int main(int argc, char const *argv[])
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> w[i] >> val[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (j < w[i]) f[i][j] = f[i - 1][j];
			else f[i][j] = max(f[i -1][j],val[i] + f[i - 1][j - w[i]]);
	cout << f[n][m];
	return 0;
}