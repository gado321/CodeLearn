#include <bits/stdc++.h>

using namespace std;

int n, t, a[100005];
long long ans, tmp;
vector <int> adj[100005];
bool ok[100005];

void dfs(int u)
{
    ok[u] = 1;
    tmp += a[u];
    ans += tmp;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!ok[v]) dfs(v);
    }
    tmp -= a[u];
}

int main(int argc, char const *argv[])
{
    freopen("SPC5.inp","r",stdin);
    freopen("SPC5.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (int i = 0; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            memset(ok,0,sizeof(ok));
            ans = 0; tmp = 0;
            dfs(i);
            printf("%lld ",(long long)(ans - a[i]));
        }
        printf("\n");
    }
    return 0;
}