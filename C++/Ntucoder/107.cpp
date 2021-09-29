#include <iostream>

using namespace std;

int n, uu, vv, d, t, a[105][105], ans;
int u[] = {0, 0, 1, -1}, v[] = {1, -1, 0, 0};

void back(int x, int y){
    for (int i = 0; i < 4; i++) {
        int xi, yi;
        xi = x + u[i];
        yi = y + v[i];
        if (!a[xi][yi]) {
            a[xi][yi] = 2;
            if (xi == d && yi == t) {
                ans = 1;
                return;
            }
            else
                back(xi, yi);
        }
    }
}

int main(){
    cin >> n >> uu >> vv >> d >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 0; i <= n + 1; i++) {
        a[0][i] = 1;
        a[n + 1][i] = 1;
        a[i][n + 1] = 1;
        a[i][0] = 1;
    }
    back(uu,vv);
    if (ans) cout << "YES";
    else cout << "NO";
    return 0;
}

// void bfs(int x, int y)
// {
//     if (x == d && y == t && !a[x][y]){
//         ans = 1;
//         return;
//     }
//     else if (x < 1 || y < 1 || x > n || y > n || a[x][y]) return;
//     else
//     {
//         a[x][y] = 1;
//         bfs(x + 1, y);
//         bfs(x - 1, y);
//         bfs(x, y + 1);
//         bfs(x, y - 1);
//     }
// }

// int main()
// {
//     cin >> n >> u >> v >> d >> t;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//             cin >> a[i][j];
//     a[u][v] = 0;
//     bfs(u, v);
//     if (ans) cout << "YES";
//     else cout << "NO";
//     return 0;
// }

