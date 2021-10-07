#include <bits/stdc++.h>

using namespace std;

int f[2000], n;
string s;
stack <char> q;

int main(int argc, char const *argv[])
{
	freopen("hoahoc.inp","r",stdin);
	freopen("hoahoc.out","w",stdout);
	cin >> s;
	int pos = 0, b = 0;
	while (b < s.size())
	{
		if (s[b] == ')' && s[b + 1] == ')') s.erase(b + 1,1);
		else if (s[b] == '(' && s[b + 1] == '(') s.erase(b + 1,1);
		else b++;
	}
	if (s[s.size() - 1] == ')') s += '1';
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(') pos++;
		else if (s[i] != '(' && s[i] != ')')
			{
				int z = 1;
				if ((int) s[i + 1] <= 57 && (int) s[i + 1] >= 50) z = s[i + 1] - '0';
				if (s[i] == 'H') f[pos] += 1 * z;
				else if(s[i] == 'C') f[pos] += 12 * z;
				else if(s[i] == 'O') f[pos] += 16 * z;
			}
		else if (s[i] == ')') 
			{
				f[pos - 1] += f[pos] * (s[i + 1] - '0');
				pos--;
				i++;
			}
	}
	cout << f[0];
	return 0;
}


