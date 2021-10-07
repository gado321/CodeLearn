#include <bits/stdc++.h>

using namespace std;

vector <int> adj[3000];
vector <int> ans[3000];
vector <int> stk;o
char a[3000][3000];
bool exist[3000];
int n, low[3000], num[3000], Time, cnt;

void taczan(int u)
{
	stk.push_back(u);
	low[u] = num[u] = ++Time;
	exist[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!num[v]) taczan(v);
		if (exist[v]) low[u] = min(low[u],low[v]);
	}
	if (num[u] == low[u])
	{
		int tmp = 0;
		while (true)
		{
			tmp++;
			int v = stk.back();
			exist[v] = 0;
			stk.pop_back();
			if (u == v) break;
		}
		if (tmp == 1) cnt++;
	}
}

int main(int argc, char const *argv[])
{
	freopen("rps.inp","r",stdin);
	freopen("rps.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			char d;
			scanf("%c",&d);
			a[i][j] = d;
			if (d == '\n') scanf("%c",&a[i][j]);

		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
		{
			if (i != j)
			{
				if (a[i][j] == '1') {adj[i].push_back(j); a[j][i] = '2';}
				else if (a[i][j] == '0') {adj[j].push_back(i); a[j][i] = '2';}
			}
		}	
	for (int i = 1; i <= n; i++)
		if (!num[i]) taczan(i);
	cout << n - cnt;
	return 0;
}