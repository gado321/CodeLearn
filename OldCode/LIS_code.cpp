#include <bits/stdc++.h>

using namespace std;

const int N = 30005;

int f[N], a[N], b[N], n, m, x;
vector <int> res;

int main(int argc, char const *argv[])
{
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		f[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
		m = max(m,f[i]);
		b[f[i]] = a[i];
	}
	cout << m << endl;
	/*int tmp = m;
	for (int i = n; i >= 1; i--)
		if (f[i] == tmp)
		{
			res.push_back(a[i]);
			tmp--;
		}*/
	return 0;
}	
