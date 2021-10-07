#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair <int,int> ii;
typedef pair <ii,ii> iiii;

ii a[100005], b[100005];
vector <int> adj[100005];
int n, r1, r2, cnt, ans;
bool ok[100005];

bool cmp(ii a, ii b)
{
	return a.fi > b.fi || (a.fi == b.fi && a.se > b.se);
}

void dfs(int u)
{
	cnt++;
	ok[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!ok[v]) dfs(v);
	}
}

int main(int argc, char const *argv[])
{
	freopen("subtree.inp","r",stdin);
	freopen("subtree.out","w",stdout);
	cin >> n >> r1; 
	for (int i = 1; i < n; i++) cin >> a[i].fi >> a[i].se;
	cin >> r2;
	for (int i = 1; i < n; i++) cin >> b[i].fi >> b[i].se;
	sort(a + 1, a + n, cmp);
	sort(b + 1, b + n, cmp);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i].fi == b[j].fi && a[i].se == b[j].se)
			{
				int u = a[i].fi, v = a[i].se;
				adj[u].push_back(v);
			}
	for (int i = 1; i <= n; i++)
		if (!ok[i])
		{
			cnt = 1;
			dfs(i);
			ans = max(ans,cnt);
		} 
	cout << ans;
	return 0;
}