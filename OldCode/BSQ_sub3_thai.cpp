#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
const long long MOD = 1e9 + 7;

int t, n, m, k, ans;
int a[N], b[N], cnt[N];

int main(int argc, char const *argv[])
{
	freopen("BQS.inp","r",stdin);
	freopen("BQS.out","w",stdout);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		ans = 0;
		memset(cnt,0,sizeof(cnt));
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {	
				long long pos = upper_bound(a + i + 1, a + n + 1,a[i] + 2) - a;
				long long tmp = pos - i - 1;
				ans = (ans + tmp) % MOD;
			}
		cout << ans % MOD << endl;
		}
	return 0;
}