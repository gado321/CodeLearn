#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int f[N], g[N], a[N], aa[N], G[N], n, mf, x, mg, ans;
vector <int> res;

void _lis(int &x)
{
	int b[N] = {};
	for (int i = 1; i <= n; i++)
		{
			f[i] = lower_bound(b + 1, b + x + 1, a[i]) - b;
			x = max(mf,f[i]);
			b[f[i]] = a[i];
		}
}

void _lds(int &x)
{
	int b[N] = {};
	for (int i = 1; i <= n; i++)
		{
			G[i] = lower_bound(b + 1, b + x + 1, aa[i]) - b;
			x = max(mg,G[i]);
			b[G[i]] = aa[i];
		}
}

int main(int argc, char const *argv[])
{
	freopen("lis.inp","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d%d",&n,&x);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	if(!x)
	{
		_lis(mf);
		cout << mf;
	}
	else
	{
		for (int i = 1; i <= n; i++) aa[i] = -a[n - i + 1];
		_lis(mf);
		_lds(mg);
		for (int i = 1; i <= n; i++) g[i] = G[n - i + 1];
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				if (a[i] - x < a[j]) ans = max(ans,f[i] + g[j]); 
		cout << ans;
	}
	return 0;
}	
