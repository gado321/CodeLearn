#include <bits/stdc++.h>

using namespace std;

string s, t;
int tmp, cnt;

int main(int argc, char const *argv[])
{
	freopen("subrep.inp","r",stdin);
	freopen("subrep.out","w",stdout);
	cin >> s;
	cin >> t;
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == s[tmp]) {
			tmp++;
			if (tmp == s.size()) {cnt++; tmp = 0;}
		}
	}
	cout << cnt;
	return 0;
}