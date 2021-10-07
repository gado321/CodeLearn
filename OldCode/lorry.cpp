#include <bits/stdc++.h>

using namespace std;

int n, v, a[100005], w[100005];
int f[10005][10005];

int main(int argc, char const *argv[])
{
	freopen("lorry.inp","r",stdin);
	freopen("lorry.out","w",stdout);
	cin >> n >> v;
	for (int i = 1; i <= n; i++) cin >> a[i] >> w[i];
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= v; j++) {
			if (j < a[i]) f[i][j] = f[i - 1][j];
			else f[i][j] = max(f[i - 1][j],f[i - 1][j - a[i]] + w[i]);
		}
	cout << f[n][v];
	return 0;
}