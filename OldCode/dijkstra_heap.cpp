#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int oo = INT_MAX;
typedef pair<int, int> ii;

priority_queue <ii, vector<ii>, greater<ii> > pq;
vector <ii> a[2309];
int n, m, t, z;
int d[2309], trace[2309];

void dijkstra(int s)
{
    for (int i = 1; i <= n; i++) d[i] = oo;
    d[s] = 0;
    pq.push(ii(s, 0));
    while (!pq.empty())
    {
        int du = pq.top().second;
        int u = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        for (int i = 0; i < a[u].size(); i++)
        {
        	int v = a[u][i].first;
            int uv = a[u][i].second;
            if (d[v] > du + uv) 
            {
                d[v] = du + uv;
                pq.push(ii(v,d[v]));
            }
        }
    }

}

int main()
{
   	cin >> n >> m;
    while (m--)
    {
    	int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v, w));
        a[v].push_back(ii(u, w));
    }
    for (int i = 1; i <= n; i++) a[i].push_back(ii(0,0));
    dijkstra(1);
	cout << d[n] << endl;
}