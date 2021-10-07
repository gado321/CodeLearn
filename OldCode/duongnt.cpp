#include <bits/stdc++.h>

using namespace std;

queue <int> q;
bool ok[100000];
vector <int> adj[100000];
int d[100000];
int prime[10000];
int n, m;

bool check_so(int m, int n)
{
	int a[5], b[5];
	a[1] = m % 10; m /= 10; a[2] = m % 10; m /= 10;
	a[3] = m % 10; m /= 10; a[4] = m % 10; m /= 10;
	b[1] = n % 10; n /= 10; b[2] = n % 10; n /= 10;
	b[3] = n % 10; n /= 10; b[4] = n % 10; n /= 10;
	int dem = 0;
	for (int i = 1; i <= 4; i++)
			if (a[i] != b[i]) dem++;
	if (dem == 1) return 1;
	return 0;
}

bool prime_check(int n)
{
	if (n < 2) return 0;+
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0) return 0;
	return 1;
}

void bfs(int u)
{
	ok[u] = 1;
	d[1] = 0;
	q.push(u);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i];
			if (!ok[v]) q.push(v), ok[v] = 1, d[v] = d[u] + 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("duongnt.inp","r",stdin);
	freopen("duongnt.out","w",stdout);
	cin >> n >> m;
	int st = 0;
	for (int i = 1000; i <= 9999; i++)
		if (prime_check(i))	prime[++st] = i;
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= st; i++)
		for (int j = 1; j <= st; j++)
			if (check_so(prime[i],prime[j])) 
			{
				adj[prime[i]].push_back(prime[j]);
				adj[prime[j]].push_back(prime[i]);
			}
	bfs(n);
	cout << d[m];
	return 0;
}