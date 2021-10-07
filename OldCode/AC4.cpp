#include <bits/stdc++.h>

using namespace std;

int n, k = 1, test, cnt, d;
char a[55][55], b[4];

int main(int argc, char const *argv[])
{
	freopen("AC4.inp","r",stdin);
	freopen("AC4.out","w",stdout);
	b[1] = 'A'; b[2] = 'B'; b[3] = 'C', b[4] = 'C';	
	scanf("%d",&test);
	while (test--)
	{
		cnt = 0;
		scanf("%d%d",&d,&n);
		for (int i = 1; i <= d; i++)
			for (int j = 1; j <= d; j++) a[i][j] = 'C';
		for (int i = 1; i <= 48; i++)
		{
			for (int j = 1; j <= 48; j++)
			{
				a[i][j] = b[k];
				k++;
				if (k == 5) { cnt++; k = 1;}
				if (cnt == n) break;
				if (j == 48) i++;
			}
			if (cnt == n) break;
		}
		printf("%d %d\n",d,d);
		for (int i = 1; i <= d; i++)
		{
			for (int j = 1; j <= d; j++) printf("%c",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}