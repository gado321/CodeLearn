/*
CODE VIP BY GA DO DEP TRAI
 */
#include <bits/stdc++.h>

using namespace std;

int adj[1005][1005], mX[1005], mY[1005], trace[1005];
int n, m, k;

int bfs() {
	queue <int> q;
	memset(trace,0,sizeof(trace));
	for (int i = 1; i <= n; i++) 
		if (!mX[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 1; v <= m; v++) {
			if (!trace[v] && adj[u][v]) {
				trace[v] = u;
				if (!mY[v]) return v;
				q.push(mY[v]);
			}
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	while (k--) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
	}
	int ans = 0;
	while (int f = bfs()) {
		while (f) {
			int x, next;
			x = trace[f]; next = mX[x];
			mX[x] = f; mY[f] = x;
			f = next;
		}
	}
	for (int i = 1; i <= n; i++) ans += (mX[i] != 0);
	cout << ans << endl;
	return 0;
}