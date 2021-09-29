#include <iostream>

using namespace std;

int n, m, u, v, a[105][105], ok[105][105], ans;

void bfs(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m || a[x][y] == 1) return;
    else {
        a[x][y] = 1;
        ans++;
        bfs(x + 1, y);
        bfs(x - 1, y);
        bfs(x, y + 1);
        bfs(x, y - 1);
    }
}

int main() {
    cin >> n >> m >> u >> v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    bfs(u, v);
    cout << ans;
    return 0;
}