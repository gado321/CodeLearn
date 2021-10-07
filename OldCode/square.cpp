#include <bits/stdc++.h>

using namespace std;

int a[1000][1000], dp[1000][10000], n, m, Max = -999999, Min, sum, ans;

int main(int argc, char const *argv[])
{
	freopen("square.inp","r",stdin);
	freopen("square.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			dp[i][j] = dp[i][j - 1] + a[i][j];}
	}
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j++)
		{
			sum = Min = 0; Max = -999999;
			for (int k = 1; k <= n; k++)
			{
				sum += dp[k][j] - dp[k][i - 1];
				Max = max(Max, sum - Min);
				Min = min(Min, sum);
			}
			ans = max(ans,Max);
		}
	cout << ans;
	return 0;
}