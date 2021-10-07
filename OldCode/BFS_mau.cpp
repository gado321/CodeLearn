#include <bits/stdc++.h>

using namespace std;

queue <int> q;
bool ok[100000];
vector <int> adj[100000];
int d[100000];
int n, m;

void bfs(int u)
{
	ok[u] = 1;
	q.push(u);
	d[1] = 0;
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
}

int main()
{
	freopen("bfs1.inp","r",stdin);
	freopen("bfs1.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(d, -1, sizeof(d));
	bfs(1);
	cout << endl;
	for (int i = 1; i <= n; i++) cout << d[i] << endl; 
	return 0;
}