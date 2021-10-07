#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair <int,int> ii;
typedef pair <ii,ii> iiii;

ii a[100005], b[100005];
vector <int> adj1[100005], adj2[100005];
int n, r1, r2, cnt, ans;
bool ok[100005];

void dfs1(int u, int k)
{
	k++;
	ok[u] = 1;
	for (int i = 0; i < adj1[u].size(); i++)
	{
		int v = adj1[u][i];
		if (!ok[v]) dfs(v);
	}
}

void dfs2(int u, int k)
{
	k++;
	ok[u] = 1;
	for (int i = 0; i < adj2[u].size(); i++)
	{
		int v = adj2[u][i];
		if (!ok[v]) dfs(v);
	}
}

int main(int argc, char const *argv[])
{
	freopen("subtree.inp","r",stdin);
	//freopen("subtree.out","w",stdout);
	cin >> n >> r1; 
	for (int i = 1; i < n; i++) 
	{
		int u, v;
		cin >> u >> v;
		adj1[u].push_back(v);
	}
	cin >> r2;
	for (int i = 1; i < n; i++) 
	{
		int u, v;
		cin >> u >> v;
		adj2[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(ok,0,sizeof(ok));
		cnt = 1;
		dfs1(i);
		memset(ok,0,sizeof(ok));
		cnt = 1;
		dfs(i);
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