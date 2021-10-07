#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair<int,int> ii;

ii a[100];
long long n, m, cnt, tmp, ans;

bool cmp(ii a, ii b) {
	return a.se < b.se;
}

int main(int argc, char const *argv[])
{
	freopen("burglar.inp","r",stdin);
	freopen("burglar.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + m + 1,cmp);
	int i = m;
	while (i > 0 && n > 0) {
		if (a[i].fi > n) ans += a[i].se * n;
		else ans += a[i].fi * a[i].se;
		n -= a[i].fi;
		i--; 
	}
	cout << ans;
	return 0;
}