#include <bits/stdc++.h>

using namespace std;

int n, m, sum, a[100005], s[100005];
long long ans;

int cut2(int l, int r, int k)
{
	int mid, ans = 0, pos = -1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] <= k) 
		{
			if (a[mid] > ans)
			{
				ans = a[mid];
				pos = mid;
			}
			l = mid + 1; 
		}
		else r = mid - 1;
	}
	return pos;
}

int main(int argc, char const *argv[])
{
	freopen("candies.inp","r",stdin);
	scanf("%d%d",&m,&n);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d",&a[i]); 
		sum += a[i]; 
		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	sum -= m; 
	int l = 0, cnt = n;
	int k = sum / cnt;
	for (int i = 1; i <= 3; i++)
	{
		if (l == -1) break;
		l = cut2(l + 1,n,k);
		cnt -= l;
		k = (sum - s[l]) / cnt;
		cout << l << endl;
	}
	return 0;
}