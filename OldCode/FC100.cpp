#include <bits/stdc++.h>

using namespace std;

string s, x;

int main(int argc, char const *argv[])
{
	x = "Free Contest 100";
	while (s != x)
	{
		getline(cin,s);
		if (s == x) {cout << "Let's start!\n";}
		else cout << "Wait\n";
	}
	return 0;
}