#include <bits/stdc++.h>

using namespace std;

int n, a[1000];
int np(int a[], int n, int k)
{
    int l = 1, r = n, res = 0;
    while ( l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] >= k)
        {
            r = m - 1;
            if (a[m] == k) res = m;
        }
        else l = m + 1;
    }
    return res;
}

int main()
{
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << np(a,n,k);
    return 0;
}
