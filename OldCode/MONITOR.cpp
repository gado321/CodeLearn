#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a, b, x, y;

int main()
{
    freopen("MONITOR.inp","r",stdin);
    freopen("MONITOR.out","w",stdout);
    cin >> a >> b >> x >> y;
    ll gcd = __gcd(x,y);
    x = x / gcd;
    y = y / gcd;
    ll x1 = a / x;
    ll x2 = b / y;
    ll n = min(x1,x2);
    cout << n * x << " " << y * n;
    return 0;
}
