#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100005];
int n, k, save[100005], len = 0;
bool ok[100005] = {};

void dfs(int u)
{
    ok[u] = 1;
    //save[len] = u;
    len++;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v;
        v = adj[u][i];
        if (ok[v] == 0) dfs(v);
    }
}

int main()
{
    //freopen("5582.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int c;
            cin >> c;
            adj[i].push_back(c);
        }
    }
    /*for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++) cout << adj[i][j] << " ";
        cout << endl;
    }*/
    dfs(k);
    //sort(save,save + len);
    cout << len << "\n";
    for (int i = 1; i <= n; i++)
        if (ok[i]) cout << i << " ";
    return 0;
}
