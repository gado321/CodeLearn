#include <bits/stdc++.h>

using namespace std;

int n, m, a[100][100], d[100], trace[100];
bool ok[100];

int dijkstra(int u, int v)
{
    memset(ok, 0, 100);
    memset(d, 10, 100);
    memset(trace, 0, 100);
    d[u] = 0;
    for (int z = 1; z <= n; z++)
    {
        int x = 0;
        int Max = 99999999;
        for (int i = 1; i <= n; i++)
            if (d[i] < Max && ok[i] == 0)
            {
                Max = d[i];
                x = i;
            }
        if (x == 0) return -1;
        if (x == v) return d[v];
        ok[x] = 1;
        for (int y = 1; y <= n; y++)
            if (a[x][y] > 0 && ok[y] == 0 && d[y] > d[x] + a[x][y])
            {
                d[y] = d[x] + a[x][y];
                trace[y] = x;
            }
    }
}

int main()
{
    freopen("try.inp","r",stdin);
    cin >> n >> m;
    memset(a, 0, 10000);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    int x = dijkstra(1,6);
    cout << x << endl;
    int z = 6;
    while (trace[z] != 0)
    {
        cout << trace[z] << " ";
        z = trace[z];
    }
    cout << endl;
    for (int i = 1; i <= n; i++) cout << trace[i] << " ";
    return 0;
}
