#include <bits/stdc++.h>

using namespace std;

string s;

int main(int argc, char const *argv[])
{
	//freopen("bb.inp","r",stdin);
	//freopen("bb.out","w",stdout);
	int n;
	cin >> n;
	while (n--)
	{
		bool c = 0;
		stack <char> stk;
		cin >> s;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
			else
			{
				if (stk.empty()) {c = 1; cout << "NO\n"; break;}
				else 
				{
					if (stk.top() == '(' && s[i] == ')') stk.pop();
					else if (stk.top() == '[' && s[i] == ']') stk.pop();
					else if (stk.top() == '{' && s[i] == '}') stk.pop();
					else {c = 1; cout << "NO\n"; break;}
				}
			}
		if (!c) cout << "YES\n"; 
	}
	return 0;
}