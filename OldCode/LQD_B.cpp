#include <bits/stdc++.h>

using namespace std;

vector <int> adj[500005];

int t, n, dem = 1, check = 1;
int a[5000000], ok[5000000], trace[5000000];

void dfs(int u)
{
	ok[u] = 1;
	cout << u << " ";
	trace[dem] = u; 
	for (int i = 0; i <= adj[u].size() - 1; i++)
	{
		int v;
		v = adj[u][i];
		if (v == a[dem + 1]){
			dem++;
			if (ok[v] == 0){ dfs(v);}
			//dem++;
		}
	}
	check = 1; 
	return;
}

int main(int argc, char const *argv[])
{
	freopen("daydx.inp","r",stdin);
	freopen("daydx.out","w",stdout);
	cin >> t;
	while (t--)
	{
		int u, v;
		cin >> n;
		for (int i = 1; i <= n - 1; i++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) cin >> a[i];
	}
	for (int i = 1; i<= n; i++)
	{
		cout << i << ": ";
		for (int j = 0; j <= adj[i].size() - 1; j++) cout << adj[i][j] << " ";
		cout << endl;
	}
	dfs(a[1]);
	cout << endl << dem;
	return 0;
}