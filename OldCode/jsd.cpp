#include <bits/stdc++.h>

using namespace std;

vector <int> adj[1000005];

int n, m, dis[1005];

void dfs(int u)
{
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (dis[v] > dis[u] + 1)
		{
			dis[v] = dis[u] + 1;
			dfs(v);
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("jsd.inp","r",stdin);
	freopen("jsd.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(dis,1e9 + 5,sizeof(dis));
	dis[1] = 0;
	for (int i = 1; i <= m; i++)
	{
		int q, u;
		scanf("%d",&q);
		if (q == 1)
		{
			scanf("%d",&u);
			if (dis[u] <= n) printf("%d\n",dis[u]);
			else printf("%d\n",-1);
		}
		else
		{
			int u, v;
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
			if (dis[v] > dis[u] + 1) 
			{
				dis[v] = dis[u] + 1;
				dfs(v);
			}
		}
	}
	return 0;
}