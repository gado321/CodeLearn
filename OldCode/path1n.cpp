#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

const int oo = 1000000;

vector <ii> adj[50005];

int q, n, a[50005];

int dijkstra(int s, int t)
{
	priority_queue < ii, vector<ii>, greater<ii> > pq;
	int d[50005];
    memset(d,oo,n + 1);
    d[s] = 0;
    pq.push(ii(0,s));
    while (!pq.empty())
    {
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (du != d[u]) continue;
        for (int i = 0; i < adj[u].size(); i++)
        {
        	int v = adj[u][i].first;
            int uv = adj[u][i].second;
            if (d[v] > du + uv) 
            {
                d[v] = du + uv;
                pq.push(ii(d[v],v));
            }
        }
    }
    return d[t];
}

int main(int argc, char const *argv[])
{
	//freopen("path1n.inp","r",stdin);
	//freopen("path1n.out","w",stdout);
	/*cin >> q;
	while (q--)
	{
		cin >> n;
		for (int i = 0; i < 50002; i++) adj[i].clear();
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) 
		{
			if (i + 1 <= n) adj[a[i]].push_back(ii(a[i + 1],1));
			if (i - 1 > 0) adj[a[i]].push_back(ii(a[i - 1],1));
			adj[i].push_back(ii(a[i],0));
		}
		cout << dijkstra(1,n) << endl;
	}*/
	set <int> t;
	t.add(1);
	return 0;
}