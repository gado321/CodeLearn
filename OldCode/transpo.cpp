#include <bits/stdc++.h>

using namespace std;

const int oo = INT_MAX;

typedef pair <int,int> ii;

vector <ii> adj[200005];
int n, m, s, t;
int d[200005];

void dijkstra(int s)
{
    priority_queue < ii, vector <ii>, greater<ii> > pq;
    d[s] = oo;
    pq.push(ii(s,d[s]));
    while (!pq.empty())
    {
        int u = pq.top().first;
        int du = pq.top().second;
        pq.pop();
        if (du > d[u]) continue;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int uv = adj[u][i].second;
            if (d[v] < min(du,uv))
            {
                d[v] = min(du,uv);
                pq.push(ii(v,d[v]));
            }
        }
    }
}
int main()
{
    freopen("transpo.inp","r",stdin);
    freopen("transpo.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(ii(v,w));
        adj[v].push_back(ii(u,w));
    }
    dijkstra(1);
    printf("%d",d[n]);
    return 0;
}