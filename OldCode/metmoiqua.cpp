#include <bits/stdc++.h>

using namespace std;

int a[1000], b[1000];
int n, m;
long long c, tam;

void quay(int i)
{
    for (int j = 1; j <= m; j++)
    {
        if (a[j] == 0)
        {
            tam = tam * 10 + b[j];
            a[j] = 1;
            if ( i == m && tam > c)
            {
                cout << tam << endl;
                c = tam;
            }
            else quay(i + 1);
            tam = tam / 10;
            a[j] = 0;
        }
    }
}

int main()
{
    //freopen("BAI41.inp","r",stdin);
    //freopen("BAI41.out","w",stdout);
    cin >> n;
    m = 0;
    while (n != 0)
    {
        m++;
        b[m] = n % 10;
        n = n / 10;
    }
    for (int i = 1; i <= m; i++) a[i] = 0;
    for (int i = 1; i < m; i++)
        for (int j = i + 1; j <= m; j++)
            if (b[i] > b[j]) swap(b[i],b[j]);
    tam = 0;
    c = 0;
    quay(1);
    return 0;
}
