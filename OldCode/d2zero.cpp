#include <bits/stdc++.h>

using namespace std;

int Q, n, d[1000005];

void bfs(int u)
{
	queue <int> q;
	d[u] = 1;
	q.push(u);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (!d[v - 1])
		{
			d[v - 1] = d[v] + 1;
			if (!(v - 1)) break;
			q.push(v - 1);
		}
		for (int i = 2; i * i <= v; i++)
			if(!(v % i))
			{
				cout << v << " ";
				int t = max(i,v / i);
				if (!d[t]) 
				{
					d[t] = d[v] + 1;
					q.push(t);
				}
			}
	}
}

int main(int argc, char const *argv[])
{
	freopen("d2zero.inp","r",stdin);
	//freopen("d2zero.out","w",stdout);
	cin >> Q;
	while (Q--)
	{
		memset(d,0,sizeof(d));
		cin >> n;
		if (!n) {cout << n << endl; continue;}
		bfs(n);
		cout << --d[0] << endl;
	}
	return 0;
}