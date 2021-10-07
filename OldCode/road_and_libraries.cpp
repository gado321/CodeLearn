#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, m, x, y, q;
bool vis[MAXN];
vector <int> adj[MAXN];

void dfs(int u)
{
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!vis[v]) dfs(v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("daydx.inp","r",stdin);
	freopen("daydx.out","w",stdout);
	cin >> q;
	while (q--)
	{
		cin >> n >> m >> x >> y;
		for (int i = 0; i < n; i++)	adj[i].clear();
		memset(vis, 0, sizeof(vis));
		while (m--)
		{
			int u, v;	
			cin >> u >> v; 
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (!vis[i]) cnt++, dfs(i);
		ll ans = LONG_LONG_MAX;
		for (int i = cnt; i <= n; i++)
			ans = min(ans, 1ll * i * x + 1ll * (n - i) * y);
		//cout << ans << "\n";
		cout << cnt;
	}
	return 0;
}