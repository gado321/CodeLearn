#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[1005][1005], e[10005];
long long f[1005][1005];
bool ok[1005];

int main(int argc, char const *argv[])
{
	freopen("izone.inp","r",stdin);
	freopen("izone.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	for (int i = 1; i <= k; i++) cin >> e[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			long long tmp = a[i + 1][j] + a[i - 1][j] + a[i][j + 1] + a[i][j - 1] + a[i + 1][j - 1] + a[i - 1][j + 1] + a[i - 1][j - 1] + a[i + 1][j + 1];
			ok[tmp] = 1;
		}
	}
	for (int i = 1; i <= k; i++) 
		if (ok[e[i]]) printf("1\n"); else printf("0\n"); 
	return 0;
}