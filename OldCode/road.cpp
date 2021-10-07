#include <bits/stdc++.h>

using namespace std;

int n, k, a[100005], dau, cuoi, ans;
long long s[100005], tmp;

void cut2()
{
	for (int i = 1; i < n; i++)
	{
		int mid, l = i + 1, r = n;
		while (l <= r)
		{
			mid = (l + r) / 2;
			long long su = (s[mid] - s[i - 1]);
			long long le = (mid - i + 1);
			if (su >= le * k)
			{
				tmp = le;
				if (tmp > ans)
				{
					ans = tmp;
					dau = i;
					cuoi = mid;	

				}
				r = mid - 1;
			}
			else l = mid + 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("road.inp","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d",&a[i]);  
		s[i] = s[i - 1] + a[i];
	}
	cut2();
	cout << dau << " " << (cuoi - dau) + 1;
	return 0;
}