#include <bits/stdc++.h>

using namespace std;

stack <char> q, pos;
string s, x;
int t = 0;

bool check(string x)
{
	stack <char> a;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '(') a.push(s[i]);
		else if (!a.empty())
			if (s[i] == ')' && a.top() == '(') a.pop(), t++;
		else if (a.empty()) return 0;
	return a.empty();
}

int main(int argc, char const *argv[])
{
	freopen("ngoac.inp","r",stdin);
	freopen("ngoac.out","w",stdout);
	cin >> x;
	for (int i = 0; i < x.size(); i++)
		if (x[i] == '(' || x[i] == ')') s+= x[i];
	if (check(s)) 
	{
		cout << t << endl;
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == '(') pos.push(i);
			if (x[i] == ')')
			{
				for (int j = pos.top(); j <= i; j++) cout << x[j];
				cout << endl;
				pos.pop();
			}
		}
	}
	else cout << -1;
	return 0;
}