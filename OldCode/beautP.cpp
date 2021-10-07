#include <bits/stdc++.h>

using namespace std;

int n, a[1005], cnt[1005];
int ans, prev;

int main(int argc, char const *argv[])
{
	freopen("beautP.inp","r",stdin);
	//freopen("beautP.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {cin >> a[i]; cnt[a[i]]++;}
	for (int i = 1; i <= 1001; i++) 
		if (cnt[i]) {prev = i; break;}
	for (int i = 1; i <= 1001; i++)
		if (cnt[i] && i != prev) {
			ans += min(cnt[i],cnt[prev]);
			prev = i;
		}
	cout << ans;
	return 0;
}