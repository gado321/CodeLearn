#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N], n, ans, tmp;

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n - 1; i++)
	{
		tmp = 0;
		for (int j = i + 1; j <= n; j++) 
		{
			if (a[i] >= tmp && a[j] >= tmp) ans++, tmp = max(tmp,a[j]);
			if (tmp > a[i]) break;
		}
	} 
	cout << ans;
	return 0;
}