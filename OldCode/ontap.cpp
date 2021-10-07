#include <bits/stdc++.h>

using namespace std;

int a[10000], n, m, b[10000], f[10000], w, ans, Min, Max, sum;
vector <int> an;

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 1; i<= n;i++) cin >> a[i];
	for (int i = 1; i <= n;i++)
	{
		f[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
		m = max(m,f[i]);
		b[f[i]] = a[i];
	}
	cout << m << endl;
	int tmp = m;
	for (int i = n; i > 0; i--)
		if (f[i] == tmp) an.push_back(a[i]), tmp--;
	for (int i = m - 1; i >= 0; i--) cout << an[i] << " ";
	return 0;
}