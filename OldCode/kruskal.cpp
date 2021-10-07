#include <bits/stdc++.h>
 
using namespace std;
 
struct day
{
	int u;
	int v;
	int w;
};
 
day adj[100000];
 
bool cmp(day a, day b)
{
	return a.w < b.w;
}
 
int n, m, root[15005], ans, edge[15005];
 
int findroot(int u)
{
	if (root[u] == u) return u;
	root[u] = findroot(root[u]);
	return root[u]; 
}
 
int main(int argc, char const *argv[])
{
	//freopen("input.inp","r",stdin);
	//freopen("input.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> adj[i].u >> adj[i].v >> adj[i].w;
	sort(adj + 1, adj + m + 1,cmp);
	//for (int i = 1; i <= m; i++) 
	//	cout << adj[i].u << " " << adj[i].v << " " << adj[i].w << endl;
	for (int i = 1; i <= n; i++) root[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int x1, x2;
		x1 = findroot(adj[i].u);
		x2 = findroot(adj[i].v);
		if (x1 != x2) root[x1] = x2, ans += adj[i].w, edge[i] = 1;
	}
	/*for (int i = 1; i <= n; i++)
	{
		if (edge[i]) cout << i << " " << endl;
	}*/
	cout << ans;
	return 0;
} 