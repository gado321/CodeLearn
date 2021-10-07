#include <bits/stdc++.h>
#define se second
#define fi first
 
using namespace std;
 
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
 
const int oo = 1e9 + 7;
 
ii XX[5];
int n, m;
int a[1005][1005], ok;
long long d[1005][1005];
 
void dijstra(int x1, int y1) {
    priority_queue <iii , vector<iii>, greater<iii> > pq;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) d[i][j] = oo;
    d[x1][y1] = a[x1][y1];
    pq.push(iii(d[x1][y1],ii(x1,y1)));
    while (!pq.empty()){
        int du = pq.top().fi;
        int u1 = pq.top().se.fi;
        int u2 = pq.top().se.se;
        pq.pop();
        if (d[u1][u2] != du) continue;
        for (int k = 1; k <= 4; k++) {
            int v1 = u1 + XX[k].fi;
            int v2 = u2 + XX[k].se;
            int uv = a[v1][v2];
            if (du + uv < d[v1][v2]) {
                d[v1][v2] = du + uv;
                pq.push(iii(d[v1][v2],ii(v1,v2)));
            }
        }
    }
}
 
void trace(int x, int y) {
    if (!x || !y || x > n || y > m) return;
    if (a[x][y] == 1) {
        ok = 1; return;
    }
    if (x == 1 && y == 1) return;
    if (d[x][y] - a[x][y] == d[x][y - 1]) trace(x,y - 1);
    if (d[x][y] - a[x][y] == d[x][y + 1]) trace(x,y + 1);
    if (d[x][y] - a[x][y] == d[x + 1][y]) trace(x + 1,y);
    if (d[x][y] - a[x][y] == d[x - 1][y]) trace(x - 1,y);
}
 
int main() {
    freopen("vluoi.inp","r",stdin);
    freopen("vluoi.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d",&a[i][j]);
    XX[1] = ii(1,0); XX[2] = ii(-1,0); XX[3] = ii(0,-1); XX[4] = ii(0,1);
    dijstra(1,1);
    trace(n,m);
    printf("%d",d[n][m] - ok);
    return 0;
}