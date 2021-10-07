#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100005];
int n, m, tmp = 0, ans[100005];
bool ok[100005];

void dfs(int u)
{
    ok[u] = 1;
    ans[u] = tmp;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!ok[v]) ok[v] = 1, dfs(v);
    }
}

int main(int argc, char const *argv[])
{
    //freopen("daydx.inp","r",stdin);
    //freopen("daydx.out","w",stdout);
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (v == 1)
        {
            adj[i].push_back(u);
            adj[u].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!ok[i]) tmp++, dfs(i);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (ans[u] != ans[v]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}