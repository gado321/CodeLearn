#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, m;
vector <int> adj[1000];
bool ok[20000] = {0}, check = 0;

void dfs(int u)
{
	ok[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v;
		v = adj[u][i];
		if (ok[v] == 0) dfs(v);
	}
}

int main(int argc, char const *argv[])
{
	freopen("bcdaisy.inp","r",stdin);
	freopen("bcdaisy.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		if (!ok[i]) 
		{
			cout << i << "\n";
			check = 1;
		}
	if (check == 0) cout << 0;
	return 0;
}