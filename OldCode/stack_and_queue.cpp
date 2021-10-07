#include <bits/stdc++.h>

using namespace std;

string x, s;

bool check(string x)
{
	stack <char> a;
	for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[') a.push(s[i]);
			else if (!a.empty())
				{
					if (s[i] == ')' && a.top() == '(') a.pop();
					if (s[i] == ']' && a.top() == '[') a.pop();
				}
			else if (a.empty()) return 0;
		}
	return a.empty() == 1;
}

int main(int argc, char const *argv[])
{
	ifstream fi("daydx.inp");
	while (!fi.eof())
	{
		getline(fi,x);
		s = "";
		for (int i = 0; i < x.size(); i++)
			if (x[i] == ')' || x[i] == '(' || x[i] == '[' || x[i] == ']') s += x[i];
		if (check(s)) cout << "YES\n"; else cout << "NO\n";
	}
	return 0;
}