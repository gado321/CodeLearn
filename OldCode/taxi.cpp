#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair <double,double> ii;

vector <ii> a[1005];
ii taxi[1005], vst[1005];
double c;
long long level[1005], f[1005][1005], p, t, s;;
bool color[1005];
queue <int> qu;

bool bfs(int s, int t)
{
    memset(level,0,sizeof(level));
    queue <int> q;
    q.push(s);
    level[s] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].fi;
            if(!level[v] && f[u][v] < a[u][i].se) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[t];
}

long long dfs(long long s, long long t, long long flow)
{
    if(s == t) return flow;
    for(int i = 0; i < a[s].size(); i++) {
        int v = a[s][i].fi;
        if(level[v] == level[s] + 1 && f[s][v] < a[s][i].se) {
            int cur = min(flow,(long long)a[s][i].se - f[s][v]);
            int tmp = dfs(v,t,cur);
            if(tmp) {
                f[s][v] += tmp;
                f[v][s] -= tmp;
                return tmp;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    //freopen("latcat.inp","r",stdin);
    //freopen("latcat.out","w",stdout);
    int k;
    cin >> k;
    while (k--) {
        cin >> p >> t >> s >> c;
        for(int i = 1; i <= p; i++){
            cin >> vst[i].fi >> vst[i].se;
        }
        for(int i = 1; i <= t; i++){
            cin >> taxi[i].fi >> taxi[i].se;
        }
        for (int i = 1; i <= t; i++)
            for (int j = 1; j <= p; j++) {
                double tmp = (abs(vst[j].fi - taxi[i].fi) + abs(vst[j].se - taxi[i].se)) * 200 / s;
                if(tmp <= c)
                {
                    a[i].push_back(ii(t + j,1));
                    a[t + j].push_back(ii(i,0));
                }
            }
        for (int i = 1; i <= t; i++) a[0].push_back(ii(i,1));
        for (int i = 1; i <= p; i++) a[t + i].push_back(ii(t + p + 1,1));
        int ans = 0;
        while(bfs(0,t + p + 1))
        {
            while(int incf = dfs(0,t + p + 1,99999999)) ans += incf;
        }
        cout << ans << endl;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
    }
    return 0;
}