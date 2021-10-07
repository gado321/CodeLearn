#include <bits/stdc++.h>

using namespace std;

int dau, dau1, cuoi, cuoi1, a[37][37], q[37] ;
bool ok[37];

/*void bfs(int u)
{
    q[1] = u;
    ok[u] = true;
    int l = 1, r = 1;
    while (l <= r)
    {
        u = q[l]; r++;
        for (int v = 1; v <= 6; v++)
    }

}*/

int main()
{
    freopen("tapcode.inp","r",stdin);
    cin >> dau >> dau1;
    cin >> cuoi >> cuoi1;
    //memset(a, 1, 37 * 37);
    for (int i = 0; i <= 37; i++)
        for (int j = 0; j <= 37; j++) a[i][j] = 1;
    for (int i = 1; i <= 3; i++)
    {
        int x, y, z, c;
        cin >> x >> y >> z >> c;
        if (x == z)
            for (int j = y; j <= c - 1; j++) a[j * 6 + 1][j * 6 + 2] = 0;
        else if (y == c)
            for (int j = x; j <= z - 1; j++) a[y - 1 * 6 + j][y * 6 + j] = 0;
    }
    for (int i = 1; i <= 36; i++){
        for (int j = 1; j <= 36; j++) cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}

