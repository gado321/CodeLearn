#include <bits/stdc++.h>

using namespace std;

int n, a[10005], f[10005];
int res = 0;

int main()
{
    freopen("DAYCHUV.inp","r",stdin);
    //freopen("DAYCHUV.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) f[i] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i - 1; j++)
            if (a[j] >= a[i])
            {
                res = f[j]++;
                //cout << res << " " << a[i] << endl;
                f[i] = min(f[i],res);
            }
    }
    for (int i = 1; i <= n; i++) cout << f[i] << " ";
    return 0;
}
