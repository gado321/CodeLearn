#include <bits/stdc++.h>

using namespace std;

int a[50005], b[50005], st[4 * 50005], n, m, q;
long long sum[50005], val[50005];


void update(int l, int r, int id) {
	if (l > r) return;
	if (l == r) {st[id] = sum[l]; return;}
	int mid = (l + r) / 2;
	update(l,mid,id * 2);
	update(mid + 1,r,id * 2 + 1);
	st[id] = max(st[id * 2],st[id * 2 + 1]);
}

int findMax(int l, int r, int x, int y, int id) {
	if (l > y || r < x) return 0;
	if (l >= x && r <= y) return st[id];
	int mid = (l + r) / 2;
	return max(findMax(l,mid,x,y,id * 2),findMax(mid + 1,r,x,y,id * 2 + 1));
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> val[i];
	for (int i = 1; i <= m; i++) {
		sum[a[i]] += val[i];
		sum[b[i] + 1] -= val[i];
	}
	for (int i = 2; i <= n; i++) sum[i] += sum[i - 1];
	update(1,n,1);
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << findMax(1,n,u,v,1) << endl;
	}
	return 0;
}