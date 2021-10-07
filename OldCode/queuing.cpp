#include <bits/stdc++.h>

using namespace std;

string s;

int main(int argc, char const *argv[])
{
	freopen("queuing.inp","r",stdin);
	freopen("queuing.out","w",stdout);
	cin >> s;
	string x = "";
	char pos;
	for (int i = 0; i <= s.size(); i++)
		if (s[i] > s[i + 1]) 
		{
			pos = s[i];
			break;
		}
	for (int i = 0; i < s.size(); i++)
		if (s[i] != pos) x += s[i];
	cout << x;
	return 0;
}