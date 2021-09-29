#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> ii;

int n, uu, vv, d, t, a[105][105], cnt;
int u[] = {0, 0, 1, -1}, v[] = {1, -1, 0, 0};
queue <ii> qu;
ii trace[100][100], step[100];

void bfs(int x, int y){
    a[x][y] = 2;
    qu.push(ii(x,y));
    while (!qu.empty()){
        ii uwu = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++){
            int xi, yi;
            xi = uwu.first + u[i];
            yi = uwu.second + v[i];
            if (!a[xi][yi]){
                qu.push(ii(xi,yi));
                a[xi][yi] = 2;
                trace[xi][yi] = ii(uwu.first,uwu.second);
            } 
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
    bfs(uu,vv);
    if (!a[d][t]) cout << 0;
    else{
        step[++cnt] = ii(d,t);
        while (trace[d][t].first && trace[d][t].second){
            step[++cnt] = ii(trace[d][t]);
            int d1 = trace[d][t].first;
            int t1 = trace[d][t].second;
            d = d1; t = t1;

        }
    }
    cout << cnt << "\n";
    for (int i = cnt; i > 0; i--) cout << step[i].first << " " << step[i].second << "\n";
    return 0;
}