#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int a[2005], b[200005];
int f[2005][200005];

int main(int argc, char const *argv[])
{
	freopen("SPC1.inp","r",stdin);
	freopen("SPC1.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) f[i][j] = 0;
		for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
		for (int i = 1; i <= m; i++) scanf("%d",&b[i]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) 
				if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
				else f[i][j] = max(f[i - 1][j],f[i][j - 1]);
		printf("%d\n",f[n][m]);
	}
	return 0;
}