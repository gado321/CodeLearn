#include <bits/stdc++.h>

using namespace std;

string s,x;
int len[1005][1005];

void truyvet(int d, int c)
{
	if (d < 1 || c < 1) return;	
    if (s[d] == x[c])
    {
        truyvet(d - 1, c - 1);
        cout << s[d];
    }
    else
    {
        if ( len[d - 1][c] > len[d][c - 1]) truyvet(d - 1,c);
        if (len[d][c - 1] >= len[d - 1][c]) truyvet(d, c - 1);
    }
}

int main()
{
	freopen("SUBLIME_testcode.inp","r",stdin);
	freopen("SUBLIME_testcode.out","w",stdout);
	cin >> s >> x;
	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j < x.size(); j++)
		{
			if (i == 0 || j == 0) len[i][j] = 0;
			if (i > 0 && j > 0 && s[i] != x[j]) len[i][j] = max(len[i - 1][j],len[i][j - 1]);
			if (i > 0 && j > 0 && s[i] == x[j]) len[i][j] = len[i - 1][j - 1] + 1;
		}
	cout << len[s.size() - 1][x.size() - 1] << "\n";
	truyvet(s.size() - 1,x.size() - 1);
	return 0;
}
