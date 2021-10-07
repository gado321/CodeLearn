#include <bits/stdc++.h>

using namespace std;

int n, m;
string s[1005], t[105];

bool ok(char a ,char b)
{
	if (a == b || char(a - 32) == b || a == char(b - 32)) return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	freopen("wordpow_1.inp","r",stdin);
	freopen("wordpow_1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= m; i++) cin >> t[i];
	for (int i = 1; i <= n; i++)
	{
		int d = 0;
		for (int j = 1; j <= m; j++)
		if (s[i].size() > t[j].size())
		{
			int c = 0;
			for (int k = 0; k < s[i].size(); k++) 
				while (ok(s[i][k],t[j][c])) {c++; break;}
			if (c == t[j].size()) d++;
		}
		printf("%d\n",d);
	}
	return 0;
}