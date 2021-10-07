#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, s, t, adj[1005][1005], maxFlow, tmp, trace[1005], f;
int ok[1005];
 
int dfs(int u, int t) {
	ok[u] = 1;
	for (int i = 1; i <= n; i++) {
		int v = adj[u][i];
		if (!ok[i] && v > 0) trace[i] = u, dfs(i,t);
	}
	return ok[t];
}

int bfs(int u, int t) {
	queue <int> q;
	q.push(u);
	ok[u] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			int v = adj[u][i];
			if (!ok[i] && v) trace[i] = u, q.push(i), ok[i] = 1;
		}
	}
	return ok[t];
}
 
int main(int argc, char const *argv[])
{
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u][v] = w;
	}
	int maxFlow = 0, tmp = t;
	while (bfs(s,t)) {
		int f = (int) 1e9;
		trace[s] = s;
		while (trace[t] != t) {
			f = min(f,adj[trace[t]][t]);
			t = trace[t];
		}
		t = tmp; maxFlow += f;
		while (trace[t] != t) {
			adj[t][trace[t]] += f;
			adj[trace[t]][t] -= f;
			t = trace[t];
		}
		t = tmp;
		for (int i = 0; i <= n; i++) {ok[i] = 0; trace[i] = 0;}
	}
	cout << maxFlow;
	return 0; 
} 