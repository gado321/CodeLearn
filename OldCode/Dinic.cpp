/*
CODE VIP BY GA DO DEP TRAI
 */
#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair<int,int> ii;

vector <ii> adj[1005];
vector <int> arr[2];
int f[1005][1005], level[1005], color[1005];
int n, m, s, t, ans;

int bfs(int s, int t) {
	memset(level,0,sizeof(level));
	queue <int> q;
	q.push(s);
	level[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].fi;
			int w = adj[u][i].se;
			if (!level[v] && f[u][v] < w) {
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	return level[t];
}

int dfs(int s, int t, int flow) {
	if (s == t) return flow;
	for (int i = 0; i < adj[s].size(); i++) {
		int v = adj[s][i].fi;
		int w = adj[s][i].se;
		if (level[v] == level[s] + 1 && f[s][v] < w) {
			int cur = min(flow,w - f[s][v]);
			int tmp = dfs(v,t,cur);
			if (tmp) {
				f[s][v] += tmp;
				f[v][s] -= tmp;
				return tmp;
			}
		}
	}
	return 0;
}

void findCut(int s, int t) {
	memset(color,0,sizeof(color));
	color[s] = 1;
	queue <int> qq;
	qq.push(s);
	while (!qq.empty()) {
		int u = qq.front();
		qq.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].fi;
			int w = adj[u][i].se;
			if (!color[v] && f[u][v] < w) color[v] = 1, qq.push(v);
		}
	}
	for (int i = 1; i <= n; i++) arr[color[i]].push_back(i);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> s >> t;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(ii(v,w));
		adj[v].push_back(ii(u,0)); 
	}
	while (bfs(s,t)) {
		while (int f = dfs(s,t,INT_MAX)) ans += f;
	}
	cout << ans << endl;
	findCut(s,t);
	for (int i = 0; i < arr[1].size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			int u = arr[1][i];
			int v = arr[0][j];
			if (f[u][v]) {
				cout << u << " " << v << endl;
			}
		}
	}
	return 0;
}