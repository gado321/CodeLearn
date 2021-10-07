#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[100000],n,m,t,ans = 0;

int main()
{
    freopen("LAVENDER.inp","r",stdin);
    freopen("LAVENDER.out","w",stdout);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i<= n; i++)
        ans += (t / m)*(m / a[i]) + (t % m / a[i]);
    cout << ans;
}
