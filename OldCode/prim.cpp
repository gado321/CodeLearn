#include <bits/stdc++.h>
 
using namespace std;
 
const int oo = 99999999;
 
typedef pair <int,int> ii;
 
vector <ii> adj[20000];
int n, m, trace[20000], d[20000], ans;
bool ok[20000];
 
int prim(int u) 
{	
    int Sum = 0;
    priority_queue < ii, vector<ii>, greater<ii> > pq;
    for (int i = 1; i <= n; i++) d[i] = oo;
    pq.push(ii(0,u)); d[u] = 0;
    while (!pq.empty()) 
    {
        ii uu = pq.top(); 
        pq.pop();
        int u = uu.second, du = uu.first;
        if (du != d[u]) continue;
        Sum += d[u]; d[u] = 0;
        for (int i = 0; i < adj[u].size(); i++)
        {
        	int v = adj[u][i].first, w = adj[u][i].second;
	        if (d[v] > w) 
	        {
	            d[v] = w;
	            pq.push(ii(d[v],v));
	        }
    	}
    }
    return Sum;
}
 
int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(ii(v,w));
		adj[v].push_back(ii(u,w));
	}
	cout << prim(1);
	return 0;
} 