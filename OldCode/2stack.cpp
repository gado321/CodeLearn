#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

string s,t;
ll a[100500], b[100500], pa[100500], pbb[100500];

int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    int n,m,x,i;
	ll tests;
	cin >> tests;
	while (tests--)
	{
		cin >> n >> m >> x;
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
			pa[i+1] = pa[i] + a[i];
		}
		for (i = 0; i < m; i++)
		{
			cin >> b[i];
			pbb[i+1] = pbb[i] + b[i];
		}
		int ans = 0;
		for (i = 0; i <= n; i++)
		{
			if (pa[i] <= x)
			   ans = max(ans, i+(int)(upper_bound(pbb, pbb+m+1, x-pa[i])-pbb-1));
			else
				break;
		}
		cout << ans << endl;
	}
    return 0;
}