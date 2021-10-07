#include <bits/stdc++.h>

using namespace std;

int n, m, maxi = 10000, ans, a[1005], d[1005];
vector <int> adj[1005];
bool ok[1005];
queue <int> q;

void bfs(int u)
{
	d[u] = 0;
	ok[u] = 1;
	q.push(u);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i];
			if (!ok[v]) {q.push(v); ok[v] = 1; d[v] = d[u] + 1;}
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("mfriend.inp","r",stdin);
	freopen("mfriend.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%d",&m);
	for (int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d",&x);
		a[x] = 1;
	}
	bfs(1);
	for (int i = 2; i <= n; i++)
		if (a[i])
			if (maxi > d[i])
			{
				maxi = d[i];
				ans = i;
			}	
	printf("%d",ans);
	return 0;
}