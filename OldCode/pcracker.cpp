#include <bits/stdc++.h>

using namespace std;

int n;
string s[15], ss, x;

bool check(string a, string b)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i]) return 0;
	return 1;
}

void back(int i)
{
	for (int j = 1; j <= n; j++)
	{
		x += s[j];
		if (x.size() <= ss.size() && check(x,ss))
		{
			if (x == ss) {cout << 1; exit(0);}
			back(i + 1);
			x.erase(x.size() - s[j].size(), s[j].size());
		}
		else {x.erase(x.size() - s[j].size(), s[j].size());}
	}
}

int main(int argc, char const *argv[])
{
	//freopen("input.inp","r",stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	cin >> ss;
	cout << ss.size() << endl;
	back(1);
	return 0;
}