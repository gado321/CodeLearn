#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair <int,int> ii;

const int N = 1e5 + 5;

ii a[100005], ans[100005];
bool ok[100005];
int n, k, test, l, r, curans, ansmax;

void quay(int i)
{
	for (int j = 1; j <= n; j++)
		if (!ok[j])
		{
			ans[i] = a[j];
			ok[j] = 1;
			if (i == k) 
			{
				l = ans[1].fi; 
				r = ans[1].se;
				//cout << l << " " << r << endl;
				curans = r - l + 1;
				for (int ii = 2; ii <= k; ii++)
				{
					//cout << ans[ii].fi << " " << ans[ii].se << endl;
					if (!(ans[ii].fi < l && ans[ii].se > r))
					{
						if (ans[ii].fi <= r && ans[ii].se <= r && ans[ii].fi >= l) 
						{
							curans = ans[ii].se - ans[ii].fi + 1;
							l = ans[ii].fi;
							r = ans[ii].se;
						}
						else if (ans[ii].fi <= r && ans[ii].se > r)
						{
							curans = r - ans[ii].fi + 1;
							l = ans[ii].fi;
						}
						else if (ans[ii].fi < l && ans[ii].se >= l)
						{
							curans = ans[ii].se - l + 1;
							r = ans[ii].se;
						}
						else 
						{
							curans = 0;
							break;
						}
					}
				}
				ansmax = max(ansmax,curans);
				//cout << curans << endl;
				//cout << "==============" << endl;	
			}
			else quay(i + 1);
			ok[j] = 0;
		}
}

int main(int argc, char const *argv[])
{
	freopen("AC2.inp","r",stdin);
	freopen("AC2.out","w",stdout);
	scanf("%d",&test);
	while (test--)
	{
		//cout << "Test " << test << endl;
		ansmax = 0;
		scanf("%d%d",&n,&k);
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			scanf("%d%d",&x,&y);
			a[i] = ii(x,y);
		}
		quay(1);
		printf("%d\n",ansmax);
	}
	return 0;
}