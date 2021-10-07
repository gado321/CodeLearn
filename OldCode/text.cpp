#include <bits/stdc++.h>
using namespace std;
vector <long> ds[100005];
bool visited[100005] = {};

void dfs(int u)
{
    visited[u] = true;
    cout << u <<  " ";

    for (int i = 0 ; i < ds[u].size() ; i++)
    {
        long v = ds[u][i];
        if (visited[v] == false)
            dfs(v);
    }
}
int main()
{
    int n , m;
    freopen("daydx.inp","r",stdin);
    freopen("daydx.out","w",stdout);
    cin >> n >> m;
    for ( int i  = 1 ; i <= m ; i++)
    {
        long u , v;
        cin >> u >> v;
        ds[u].push_back(v);
        ds[v].push_back(u);
    }
    for ( int i  = 0 ; i <= n; i++)
    {
        visited[i] = false;
    }
    for(int i = 0 ; i < n; i++)
    {

        if (visited[i] == false)
        {
            dfs(i);
            cout << endl;

        }
    }

    return 0;
}