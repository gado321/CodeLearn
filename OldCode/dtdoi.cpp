#include <bits/stdc++.h>

using namespace std;

const long long oo = 10000000;

int n, a[105], f[100000005];
long long s;

int main(int argc, char const *argv[])
{
	freopen("dtdoi.inp","r",stdin);
	freopen("dtdoi.out","w",stdout);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= s; i++) f[i] = oo;
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= s; j++)
				f[j] = min(f[j],f[j - a[i]] + 1);
	}
	cout << f[s];
	return 0;
}