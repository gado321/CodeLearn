#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair<int,int> ii;

ii a[50005];
int n, q;
long long sum[50005], val[50005], ans;

int main(int argc, char const *argv[])
{
	//freopen("arrm.inp","r",stdin);
	//freopen("arrm.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= q; i++) cin >> a[i].fi >> a[i].se >> val[i];
	for (int i = 1; i <= q; i++) {
		sum[a[i].fi] += val[i];
		sum[a[i].se + 1] -= val[i];

	}
	for (int i = 2; i <= n; i++) sum[i] += sum[i - 1];
	for (int i = 1; i <= n; i++) cout << sum[i] << " "; cout << endl;
 	for (int i = 1; i <= n; i++) ans = max(ans,sum[i]);
	cout << ans;
	return 0;
}