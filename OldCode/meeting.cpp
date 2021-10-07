#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#define fi first
#define se second

using namespace std;

const int oo = INT_MAX;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

vector <iii> a[2309];
int n, m, t, z, k;
int d[2309], time[2309], trace[2309], ok[2309];

void dijkstra(int s)
{
    priority_queue <iii, vector<iii>, greater<iii> > pq;
    for (int i = 1; i <= n; i++) d[i] = oo;
    for (int i = 1; i <= n; i++) time[i] = oo;
    d[s] = 0; time[s] = 0;
    pq.push(iii(ii(0,0),s));
    while (!pq.empty())
    {
        int du = pq.top().fi.fi;
        int time_ = pq.top().fi.se;
        int u = pq.top().se;
        pq.pop();
        if (du != d[u]) continue;
        for (int i = 0; i < a[u].size(); i++)
        {
        	int v = a[u][i].se;
            int uv = a[u][i].fi.fi;
            int curTime = a[u][i].fi.se;
            if (d[v] > du + uv && min(time[v],time_ + curTime) < k) 
            {
                d[v] = du + uv;
                time[v] = min(time[v],curTime + time_);
                pq.push(iii(ii(d[v],time[v]),v));
            }
        }
    }

}

int main()
{
    freopen("meeting.inp","r",stdin);
    freopen("meeting.out","w",stdout);
   	cin >> k >> n >> m;
    while (m--)
    {
    	int u, v, w, x;
        cin >> u >> v >> w >> x;
        a[u].push_back(iii(ii(w,x),v));
        a[v].push_back(iii(ii(w,x),u));
    }
    for (int i = 1; i <= n; i++) a[i].push_back(iii(ii(0,0),0));
    cin >> t >> z;
    dijkstra(t);
	if (d[z] < oo) cout << d[z] << endl;
    else cout << -1 << endl;
}