#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

const int N = (int) 1e7 + 5;

int a[N], check[N], pos[N];
long long kq[N];
int n, Max = 0;

long long Pow(int a,int n)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    long long temp = Pow(a, n / 2);
    if (n % 2 == 0) return temp * temp;
    else return temp * temp * a;
}

int main()
{
    //freopen("sumprim.inp","r",stdin);
    //freopen("sumprim.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> a[i]; Max = max(Max,a[i]);}
    for (int i = 1; i <= Max; i++) {check[i] = 1; pos[i] = 0;}
    check[1] = 0;
    for (int i = 1; i <= sqrt(Max); i++)
        if (check[i] == 1)
            for (int j = 2 * i; j <= Max; j += i) check[j] = 0;
   for (int i = 1; i <= n; i++)
    if (check[a[i]] == 1) cout << a[i] + 1 << endl;
    else if (check[a[i]] == 0 && pos[a[i]] == 0)
    {
        int x = 2, res = a[i];
        kq[a[i]] = 1;
        while (res > 1)
        {
            int dem = 0;
            while (res % x == 0)
            {
                dem++;
                res = res / x;
            }
            kq[a[i]] *= (Pow(x, dem + 1) - 1) / (x - 1);
            if (check[res] == 1) { kq[a[i]] *= ++res; break;}
            x++;
        }
        pos[a[i]] = 1;
        cout << kq[a[i]] << endl;
    }
    else if (check[a[i]] == 0 && pos[a[i]] == 1) cout << kq[a[i]] << endl;
    return 0;
}
