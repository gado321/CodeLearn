#include <bits/stdc++.h>

using namespace std;
 
int a, b, c, test, cur, cnt;
long long tmp;

int main()
{
	freopen("AC1.inp","r",stdin);
	freopen("AC1.out","w",stdout);
	scanf("%d",&test);
	while (test--)
	{
		tmp = 0;
		scanf("%d%d%d",&a,&b,&c);
		for (int i = 0; i <= a; i++)
			for (int j = 0; j <= b; j++)
				{
					cur = i ^ j;
					if (cur <= c) tmp++;
				}
		printf("%lld\n",tmp);
 	}
    return 0;
}