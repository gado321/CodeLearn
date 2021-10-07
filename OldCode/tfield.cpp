#include <bits/stdc++.h>

using namespace std;

struct ed
{
	long long x;
	long long y;
};

ed edge[1005][1005];
int n, k, nn, color[1005], d[1005];
ed s[1005];
long long ans;

bool cmp(ed a, ed b)
{
	return b.y < a.y;
}

int main(int argc, char const *argv[])
{
	cin >> n >> k;
	memset(s,0,sizeof(s));
	for (int i = 1; i <= n; i++)
	{
		cin >> nn >> s[i].x;
		for (int j = 1; j <= nn; j++)
			cin >> edge[i][j].x >> edge[i][j].y;
		edge[i][nn + 1].x = edge[i][1].x;
		edge[i][nn + 1].y = edge[i][1].y;
		long long ss = 0;
		for (int j = 1; j <= nn; j++)
			ss += (edge[i][j].x - edge[i][j + 1].x) * (edge[i][j + 1].y + edge[i][j].y);
		s[i].y = abs(ss);
	}
	sort(s + 1,s + n + 1,cmp);
	for (int i = 1; i <= n; i++)
	{
		int cmax = 0;
		for (int k = 1; k <= 100; k++) d[k] = 0;
		for (int j = i; j <= n; j++)
		{
			d[s[j].x]++;
			cmax = max(cmax,d[s[j].x]);
			if (j - i + 1 - cmax <= k) ans = max(ans,s[i].y - s[j + 1].y);
			for (int i = 1; i <= n; i++)   
		}
	}
	cout << ans / 2 << "." << ((ans % 2) * 10) / 2;
	return 0;
}