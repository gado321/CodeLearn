#include <bits/stdc++.h>

using namespace std;

int a[10000][10000], q[10000];
int n, m;
bool ok[10000];

void bfs(int u)
{
    q[1] = u;
    int l = 1, r = l;
    ok[u] = true;
    while (l <= r)
    {
        u = q[l]; l++;
        for (int v = 1; v <= n; v++)
            if (ok[v] == false && a[u][v] == 1)
            {
                r++;
                q[r] = v;
                ok[v] = true;
            }
    }
}

int main()
{
    freopen("BFS2.inp","r",stdin);
    memset(a,0,10000);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    memset(ok,0,10000);
    memset(q,0,10000);
    bfs(1);
    for (int i = 1; i <= n; i++) cout << q[i] << " ";
    return 0;
}
