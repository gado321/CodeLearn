#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

int t, n, m, k, ans;
int a[N], b[N], cnt[N];

int main(int argc, char const *argv[])
{
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		ans = 0;
		memset(cnt,0,sizeof(cnt));
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			int pleft = 0, pright = 0;	
			cnt[a[i]]++;
			for (int j = a[i]; j <= a[i] + k; j++) {
				pleft = lower_bound(a + 1, a + n + 1,j) - a;
				pright = upper_bound(a + 1, a + n + 1,j) - a;
				ans += (pright - pleft);
			}
			ans-= cnt[a[i]];
		}
	cout << ans << endl;
	}
	return 0;
}