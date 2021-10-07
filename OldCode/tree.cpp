#include <bits/stdc++.h>

using namespace std;

typedef pair <int,int> ii;

vector <ii> adj[100005];
int n, m, c[100005], h[100005], p[100005][6] = {};
bool ok[100005];

void dfs(int u)
{
	ok[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i].first;
		if (!ok[v])
		{
			h[v] = h[u] + 1;
			c[v] = u;
			dfs(v);
		}
	}
}

void sinhp()
{
	for (int i = 1; i <= n; i++) p[i][0] = c[i];
	for (int i = 1; (1 << i) <= n; i++)
		for (int u = 1; u <= n; u++)
			p[u][i] = p[p[u][i - 1]][i - 1];
}

int LCA(int u, int v)
{
	for (int i = log2(n); i >= 0; i--)
		if ((1 << i) & (abs(h[u] - h[v])) > 0)
			u = p[u][i];
	for (int i = log2(n); i >= 0; i--)
		if (p[u][i] != p[v][i])
		{
			u = p[u][i];
			v = p[v][i];
		}
	return c[u];
}

int main(int argc, char const *argv[])
{
	freopen("road.inp","r",stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(ii(v,w));
	}
	h[1] = 1;
	dfs(1);
	sinhp();
	cout << LCA(7,2);
	return 0;
}