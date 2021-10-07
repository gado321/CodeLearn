#include <bits/stdc++.h>

using namespace std;

long long n, k;
int a[100005];
long long s, cnt, tmp;

int main(int argc, char const *argv[])
{
	freopen("wires.inp","r",stdin);
	freopen("wires.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i = 1; i <= n; i++) {scanf("%d",&a[i]); s += a[i];}
	s = s / k;
	long long l = 1, r = s;
	long long mid; 
	while (l <= r)
	{
		tmp = 0;
		mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) tmp += (a[i] / mid);
		if (tmp >= k) {cnt = max(cnt,mid); l = mid + 1;}
		else if (tmp < k) r = mid - 1;
	}
	printf("%lld",cnt);
	return 0;
}