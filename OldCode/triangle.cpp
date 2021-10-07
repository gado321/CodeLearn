#include <bits/stdc++.h>

using namespace std;

int q, n, w, cnt;
int a[1005], b[1005], c[1005];

int main(int argc, char const *argv[])
{
	freopen("triangle.inp","r",stdin);
	freopen("triangle.out","w",stdout);
	cin >> q;
	while (q--)
	{
		int n, w;
		cin >> n >> w;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 1; i <= n; i++) cin >> c[i];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				int x = upper_bound(c + 1, c + n + 1,abs(a[i] - b[j])) - c;
				int y = lower_bound(c + 1, c + n + 1,abs(a[i] + b[j]) - 1) - c;
				cnt += y - x;

			}
		if (w == 3) cout << cnt << endl;
	}
	return 0;
}