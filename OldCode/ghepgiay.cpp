#include <bits/stdc++.h>

using namespace std;

int n, m, a[10005], b[10005], ans, tmp = INT_MAX, pos;

int main(int argc, char const *argv[])
{
	freopen("ghepgiay.inp","r",stdin);
	sfreopen("ghepgiay.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	for (int i = 1; i <= m; i++) scanf("%d",&b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	if (m == n)
	{ 
		for (int i = 1; i <= n; i++) ans = max(ans,abs(a[i] - b[i]));
		printf("%d",ans);
	}
	else
	{
		if (n < m)
		{
			for (int i = 1; i <= m; i++) swap(a[i],b[i]);
			swap(m,n);
		}
		for (int i = 1; i <= n - m + 1; i++)
			if (abs(a[i] - b[1]) < tmp)
			{
				tmp = abs(a[i] - b[i]);
				pos = i;
			}
		for (int i = m; i > 0; i--) b[i + pos - 1] = b[i];
		for (int i = pos; i <= n; i++) ans = max(ans,abs(a[i] - b[i]));
		printf("%d",ans);
	}
	return 0;
}