#include <bits/stdc++.h>

using namespace std;

int a[10005];

void qs(int l, int r)
{
    int i = l, j = r;
    srand(time(NULL));
    int m = a[l + rand() % (r - l + 1)];
    while (i <= j){
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (l < j) qs(l,j);
    if (i < r) qs(i,r);
}

int main()
{
    freopen("stamps.inp","r",stdin);
    //freopen("stamps.out","w",stdout);
    int s, n;
    long long t = 0;
    cin >> s >> n;
    for (int i = 1; i <= n; i++){ cin >> a[i]; t += a[i]; }
    qs(1,n);
    if (t < s) cout << 0;
    else{
        int dem = 0; t = 0;
        for (int i = n; i >= 1; i--){
            t = t + a[i];
            dem++;
            if (t >= s) break;
        }
        cout << dem;
    }
    return 0;
}
