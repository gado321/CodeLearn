#include <bits/stdc++.h>

using namespace std;

long long a[10000], f[1000][1000], n;

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	//for (int i = 1; i<= n; i++) f[i][i + 1] = a[i] * a[i + 1];
	int i = 1, k = 3, j = k;
	for (int i = n; i >= 1; i--)
        for (int j = n + 1; j <= n; j++)
        {
            f[i][j] = a[i] * a[j] + f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
        }
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) printf("%lld",f[i][j]);
		printf("\n");
	}
	return 0;
}
