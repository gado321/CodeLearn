#include <bits/stdc++.h>

using namespace std;

vector <int> adj[1000];
bool ok[1000];
int n, m,U,V, trace[1000] = {},dem=0;

void dfs(int u)
{
    ok[u] = 1;
	cout << u << " ";
	for (int i = 0; i <= adj[u].size() - 1; i++)
	{
	    int v;
		v = adj[u][i];
		if (ok[v] == 0) dfs(v), trace[v] = u;
	}
}


int main()
{
    memset(ok,0,n + 1);
    freopen("dothi.inp","r",stdin);
    cin >> n >> m >> U >> V;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <=n; i++)
    {
        cout <<i<< ": ";
        for (int j = 0; j < adj[i].size(); j++) cout << adj[i][j] << " ";
        cout << endl;
    }
    dfs(U); cout << endl;
    if(!ok[V]) {cout<<'0'; return 0;}
    int i = V;
    while (i != 0)
    {
       cout << i << " ";
       i = trace[i];
    }
    return 0;
}
