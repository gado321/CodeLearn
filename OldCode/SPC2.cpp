#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair<int,int> ii;

ii a[100005], b[100005];
int t, n;
long long sum, mau;
bool ok[100005];

bool cmp(ii a, ii b) {return a.se < b.se;}

void back(int i,ii a[])
{
    for (int j = 1; j <= n; j++)
        if (!ok[j])
        {
            ok[j] = 1;
            a[j].se = i;
            if (i == n)
            {   
                for (int k = 1; k <= n; k++) {b[k].fi = a[k].fi; b[k].se = a[k].se;}
                sort(b + 1, b + n + 1, cmp);
                for (int k = 1; k <= n; k++) sum += abs(b[k].fi - b[k - 1].fi); 
            } 
            else back(i + 1,a);
            ok[j] = 0;
        }
}

int main(int argc, char const *argv[])
{
    freopen("SPC2.inp","r",stdin);
    freopen("SPC2.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        sum = 0;
        scanf("%d",&n);
        memset(ok,0,n + 1);
        for (int i = 1; i <= n; i++) scanf("%d",&a[i].fi);
        a[0].fi = 0;
        mau = 1;
        for (int i = 1; i <= n; i++) mau *= i;
        back(1,a);
        long long gc = __gcd(sum,mau);
        cout << sum / gc << " " << mau / gc << "\n";
    }
    return 0;
}