#include <bits/stdc++.h>

using namespace std;

queue <char> a;
string s;
int n;

int main(int argc, char const *argv[])
{
	//freopen("daydx.out","w",stdout);
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++) a.push(s[i]);
	while (n--)
	{
		a.push(a.front());
		a.pop();
	}
	while (!a.empty())
    {
        cout << a.front();
        a.pop();
    }
	return 0;
}