#include <bits/stdc++.h>

using namespace std;

int a[1000][1000];
int n, m;
bool ok[1000], check[1000];

void dfs(int u)
{
    ok[u] = 1;
    check[u] = 1;
    for (int v = 1; v <= n; v++)
        if (ok[v] == 0 && a[u][v] == 1) dfs(v);
}

int main()
{
    freopen("dodeptrai.inp","r",stdin);
    cin >> n >> m;
    memset(a, 0, 1000000);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    int Count = 0;
    memset(check, 0, 1000);
    for (int i = 1; i <= n; i++)
        if (check[i] == 0)
        {
            dfs(i);
            cout << endl;
            Count++;
        }
    cout << Count;
    return 0;
}
