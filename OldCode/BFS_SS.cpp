#include <bits/stdc++.h>

using namespace std;
int m, n, c, s;
bool ok[10000];

int main(int argc, char const *argv[])
{
	freopen("daydx.inp","r",stdin);
	freopen("daydx.out","w",stdout);
	cin >> c;
	while (c--)
	{
		vector <int> adj[10000];
		queue <int> q;
		int d[10000];
		memset(ok,0,sizeof(ok));
		memset(d,0,sizeof(d));
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int u; cin >> u; int z = u;
		ok[u] = 1; d[u] = 0;
		q.push(u);
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
		//for (int i = 1; i<= n; i++) cout << d[i] << " "; 
		for (int i = 1; i <= n; i++) 
			if (i != z && d[i] != 0) cout << d[i] * 6 << " ";
			else if (i != z && d[i] == 0) cout << -1 << " ";
		cout << endl; 
	}
	return 0;
}