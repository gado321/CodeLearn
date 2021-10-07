#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair <int,int> ii;

int test, n, k, curans, ansmax;
int c[55], v[55], ch[55], cnt[55], b[55];
bool ok[55];

void quay(int i)
{
	for (int j = 1; j <= n; j++)
		if (!ok[j])
		{
			cnt[c[j]]++;
			if (cnt[c[j]] <= k)
			{
				ok[j] = 1;
				ch[i] = v[j]; 
				if (i == 2 * k)
				{
					curans = 0;
					for (int ii = 1; ii <= 2 * k; ii++) 
						if (ch[ii]) curans += ch[ii];
						else 
						{
							curans = 0; 
							break;
						}
					if (!curans) ansmax = -1;
					else ansmax = max(curans,ansmax);
				}	
				else quay(i + 1);
				ok[j] = 0;
				for (int i = 1; i <= n; i++)
					if (!(cnt[i]) == cnt[j]) b[cnt[i]]++; 
				cnt[c[j]]--;
			}
			else 
			{
				ansmax = -1; 
				return;
			}
		}
}

int main(int argc, char const *argv[])
{
	freopen("AC4.inp","r",stdin);
	freopen("AC4.out","w",stdout);
	scanf("%d",&test);
	while (test--)
	{
		ansmax = -1;
		scanf("%d%d",&n,&k);
		for (int i = 1; i <= n; i++) scanf("%d%d",&c[i],&v[i]);
		if (!k) cout << 0 << endl;
		else
		{
			for (int i = 1; i <= 50; i++) ch[i] = 0; 
			quay(1);
			cout << ansmax << endl;	
		}
	}
	return 0;
}