#include <iostream>

using namespace std;

typedef pair<int,int> ii;

int X[] = {0, 1}, Y[] = {1, 0};
int n, m, cnt, a[30][30], ok[5], check, num;
ii trace[50][50], step[50];

void back(int x, int y){
    if (check) return;
    for (int i = 0; i < 2; i++){
        int u, v;
        u = x + X[i];
        v = y + Y[i];
        if (a[u][v] == -1) continue;
        if (!ok[a[u][v]] && a[u][v]){
            cnt++;
            ok[a[u][v]] = 1;
        }
        trace[u][v] = ii(x,y);
        if (cnt >= 2 && !a[u][v]){
            check = 1;
            return;
        }
        else back(u,v);
        if (ok[a[u][v]] && a[u][v]){
            cnt--;
            ok[a[u][v]] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 0; i <= n + 1; i++){
        a[i][0] = -1;
        a[i][m + 1] = -1;
    }
    for (int i = 0; i <= m + 1; i++){
        a[n + 1][i] = -1;
        a[0][i] = -1;
    }
    back(1,1);
    if (!check){
        cout << -1;
        return 0;
    }
    step[++num] = ii(n,m);
    while (trace[n][m].first && trace[n][m].second){
        step[++num] = ii(trace[n][m]);
        int d1 = trace[n][m].first;
        int t1 = trace[n][m].second;
        n = d1; m = t1;
    }
    for (int i = num; i > 0; i--) cout << step[i].first << " " << step[i].second << "\n";
    return 0;
}