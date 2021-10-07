#include <bits/stdc++.h>

using namespace std;

const int oo = 99999;

int a[1000], n, ans, k, m;
int f[10000];

int main(int argc, char const *argv[])
{
	//freopen("tien.inp","r",stdin);
	//freopen("tien.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) f[i] = oo;
	for (int i = 1; i <= n; i++)
		for (int j = a[i]; j <= m; j++)
			if (f[j] > f[j - a[i]]) f[j] = f[j - a[i]] + a[i];
	for (int i = 1; i <= m; i++) cout << f[i] << " ";
	return 0;
}