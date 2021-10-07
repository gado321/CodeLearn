#include <bits/stdc++.h>

using namespace std;

string s;
int f[1000][1000];

void trace(int x, int y)
{
	if (!f[x][y]) return;
	if (f[x][y - 1] < f[x + 1][y]) 
	{
		trace(x, y - 1);
		cout << s[x];
	}
	else {trace(x + 1, y); cout << s[y];}

}

int main(int argc, char const *argv[])
{
	cin >> s;
	s = ' ' + s;
	//cout << s;
	for (int i = 1; i < s.size() - 1; i++)
		if (s[i] == s[i + 1]) f[i][i + 1] =  0;
		else f[i][i + 1] = 1;
	int i = 1, k = 3, j = k;
	while (i == 1 && j != s.size() - 1)
	{
		while (j < s.size())
		{
			if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
			else if (s[i] != s[j]) f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
			i++; j++;
		}
		i = 1;
		j = ++k;
	}
	f[1][s.size() - 1] = min(f[1][s.size() - 2],f[2][s.size() - 1]) + 1;
	for (int i = 1; i < s.size(); i++){
		for (int j = 1; j < s.size(); j++) cout << f[i][j] << " ";
		cout << endl;
	}
	trace(1,s.size() - 1);
	return 0;
}

