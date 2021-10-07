#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair<int,int> ii;

ii a[100005];
long long sum[5000005], ans;
int n, k, maxi;

bool cmp(ii a, ii b) {
  return a.se < b.se;
}

int main(int argc, char const *argv[])
{
  freopen("squid.inp","r",stdin);
  freopen("squid.out","w",stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {cin >> a[i].fi >> a[i].se; maxi = max(maxi,a[i].se);}
  sort(a + 1, a + n + 1,cmp);
  for (int i = 1; i <= n; i++) sum[a[i].se] = sum[a[i - 1].se] + a[i].fi;
  for (int i = 1; i <= maxi + k; i++) 
    if (!sum[i]) sum[i] = sum[i - 1];
  for (int i = k; i <= maxi; i++) {
    ans = max(ans,sum[i + k + 1] - sum[i - k]);
  }
  cout << ans;
  return 0;
}