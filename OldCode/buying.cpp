#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#define fi first
#define se second

using namespace std;

typedef pair<long long,long long> ii;

int n;
long long b, cost, ans = 0;
ii a[100005];

int main(int argc, char const *argv[])
{
	freopen("buying.inp","r",stdin);
	freopen("buying.out","w",stdout);
	cin >> n >> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
	}
	sort(a + 1, a + n + 1);
 	int i = 1;
	for (int i = 1; i <= n; i++) {
		long long tmp = b / a[i].fi;
		if (tmp >= a[i].se) {
			b -= a[i].fi * a[i].se;
			ans += a[i].se;
		}
		else {
			b -= tmp * a[i].fi;
			ans += tmp;
		}
		if (b <= 0) break;
	}
	cout << ans;
	return 0;
}