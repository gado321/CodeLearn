#include <bits/stdc++.h>
#include <fstream>

using namespace std;

string a[100000], s, x;
int n, dem;

int main(int argc, char const *argv[])
{
	ifstream fi("daydx.inp");
	freopen("daydx.out","w",stdout);
	int t = 1;
	while (!fi.eof()) {fi >> a[t]; t++;}
	for (int i = 1; i < t; i++) s += a[i];
	for (int i = 0; i < s.size(); i++)
	{
		x = "";
		for (int j = i; j <s.size(); j++)
		{
			x += s[j];
			int tmp;
			tmp = x.find("11");
			if (tmp > -1) break; else dem++;
		}
	}
	cout << dem;
	return 0;
}