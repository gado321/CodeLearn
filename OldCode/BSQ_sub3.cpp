#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
const long long MOD = 1e9 + 7;

int t, n, m, k, ans;
int a[N];

int main(int argc, char const *argv[])
{
	freopen("BSQ.inp","r",stdin);
	freopen("BSQ.out","w",stdout);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		ans = 0;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {	
				long long pos = upper_bound(a + i + 1, a + n + 1,a[i] + k) - a;
				long long count = pos - i - 1;
				ans = (ans + count) % MOD;
			}
		cout << ans % MOD << endl;
		}
	return 0;
}