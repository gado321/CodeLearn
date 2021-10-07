#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const long long oo = 1e9;
typedef pair<long long, int> ii;

vector <ii> a[100000];
int n, m, s, k;
long long d[100000];

void dijkstra(int s)
{
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    for (int i = 1; i <= n; i++) d[i] = oo;
    d[s] = 0;
    pq.push(ii(0,s));
    while (!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        for (int i = 0; i < a[u].size(); i++)
        {
        	int v = a[u][i].first;
            int uv = a[u][i].second;
            if (d[v] > du + uv) 
            {
                d[v] = du + uv;
                pq.push(ii(d[v],v));
            }
        }
    }

}

int main(int argc, char const *argv[])
{
    freopen("xedien.inp","r",stdin);
    freopen("xedien.out","w",stdout);
   	scanf("%d%d%d%d",&n,&m,&s,&k);
    for (int i = 1; i <= m; i++)
    {
    	int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back(ii(v, w));
        a[v].push_back(ii(u, w));
    }
    dijkstra(s);
	for (int i = 1; i <= n; i++) 
        if(i != s && d[i] * 2 <= k) printf("%d ",i);
}