#include <bits/stdc++.h>

using namespace std;

int n, q;

int bfs(int n) {
	// queue <int> q;
	// int d[100005], ok[100005];
	// memset(d,0,sizeof(d));
	// memset(ok,0,sizeof(ok));
	// ok[0] = 1;
	// q.push(0);
	// while (!q.empty()) {
	// 	int u = q.front();
	// 	if (u > n) break;
	// 	q.pop();
	// 	if (!ok[u + 1]) {ok[u + 1] = 1; q.push(u + 1); d[u + 1] = d[u] + 1;}
	// 	if (!ok[u * 2]) {ok[u * 2] = 1; q.push(u * 2); d[u * 2] = d[u] + 1;}
	// }
	// return d[n];
	int ans = 0;
	while (n) {
		if (n % 2 != 0) {
			n--;
			ans++;
		}
		else {
			n /= 2;
			ans++;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	freopen("operations.inp","r",stdin);
	freopen("operations.out","w",stdout);
	cin >> q;
	while (q--) {
		cin >> n;
		cout << bfs(n) << endl;
	}
	return 0;
}