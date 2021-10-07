#include <bits/stdc++.h>

using namespace std;

queue <int> q;
bool ok[100005];
vector <int> adj[100005];
int d[100005], tracu[100005], ans[100005];
int n, m, kq = 0, pos;

void dfs(int u)
{
	ok[u] = 1;
	//cout << u << " ";
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!ok[v]) 
		{
			tracu[v] = u; d[v] = d[u] + 1; 
			if (kq < d[v]) kq = d[v], pos = v;
			ok[v] = 1;
			dfs(v); 
		}
	}
}

int bfs(int u)
{
	memset(d, 0, sizeof(d));
	memset(ok, 0, sizeof(ok));
	ok[u] = 1;
	q.push(u);
	d[1] = 1;
	while (!q.empty())
	{
		u = q.front(); 
		q.pop();
		for (int i = 0; i < adj[u].size(); i++)
			{
				int v = adj[u][i];
				if (!ok[v]) q.push(v), ok[v] = 1, d[v] = d[u] + 1;
			}
	}
	return u;
}

int main()
{
	freopen("daydx.inp","r",stdin);
	freopen("daydx.out","w",stdout);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int z = bfs(1);
	memset(d, 0, sizeof(d));
	memset(ok, 0, sizeof(ok));
	dfs(z);
	cout << ++kq << endl;
	int m = pos, p = 0;
	while (m != 0)
	{
		//cout << m << " ";
		ans[++p] = m;
		m = tracu[m];
	}
	if (kq % 2 != 0)
		cout << 1 << endl << ans[kq / 2 + 1];
	else 
	{
		cout << 2 << endl;
		cout << ans[kq / 2] << " " << ans[kq / 2 + 1];
	}
	return 0;
}

