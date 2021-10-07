#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n, m, t, check, a[N], d[N];
vector <int> adj[N];
int ok[N];
queue <int> q;

void dfs(int u)
{
	ok[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!ok[v]) dfs(v);
		else if (ok[v] == 1) check = 1; 
	}
	ok[u] = 2;
}

int main(int argc, char const *argv[])
{
	freopen("circleg.inp","r",stdin);
	freopen("circleg.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		for (int i = 1; i <= N; i++) adj[i].clear();
		memset(ok,0,sizeof(ok));
		scanf("%d%d",&n, &m);
		check = 0;
		for (int i = 1; i <= m; i++) 
		{
			int u, v;
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; i++)
			if (!ok[i]) dfs(i);
		cout << check << endl;
	}
	return 0;
}