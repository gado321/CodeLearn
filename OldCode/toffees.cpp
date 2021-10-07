#include <bits/stdc++.h>

using namespace std;

int n, cl = 0, cb = 1, a[1000005];
string s;

int main(int argc, char const *argv[])
{
	freopen("toffees.inp","r",stdin);
	//freopen("toffees.out","w",stdout);
	cin >> n >> s;
	n--;
	int i = 0;
	while (i < s.size()) {
		int cnt = 1;
		for (int j = i + 1; i < s.size(); j++) {
			if (s[i] == s[j]) cnt++; else break;
		}
		int tmp = cnt;
		if (s[i] == 'L') {
			++cnt;
			for (int k = i; k <= i + tmp; k++) {a[k] = cnt--;}
			//cl = a[tmp];
			cb = a[tmp] - 1;
		}
		else if (s[i] == 'R') {
			for (int k = i; k <= i + tmp; k++) {
				a[k] = (k - i + 1) + cl; 
			}
			//cl = a[tmp];
			cb = a[tmp] - 1;
		}
		else {
			for (int k = i; k <= i + tmp; k++) a[k] = 1;
			cb = a[tmp];
			cl = cb; 
		}
		i += tmp + 1;
		//break;
	}
	if (s[s.size() - 1] == 'L') a[n] = 1;
	else if (s[s.size() - 1] == 'R') a[n] = a[n - 1] + 1;
	for (int i = 0; i <= n; i++) cout << a[i] << " ";
	return 0;
}