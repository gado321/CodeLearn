#include <bits/stdc++.h>

using namespace std;

int a[50005];

void qs( int l, int r)
{
    int i = l, j = r;
    srand(time(NULL));
    int m = a[l + rand() % (r-l+1)];
    while (i <= j){
        while (abs(a[i]) < abs(m)) i++;
        while (abs(a[j]) > abs(m)) j--;
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
    freopen("explore.inp","r",stdin);
    freopen("explore.out","w",stdout);
    long long t; int n;
    cin >> t >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    qs(1,n);
    //for ( int i = 1; i <= n; i++) cout << a[i] << " ";
    int res = abs(a[1]), dem = 1;
    //a[0] = 0;
    for (int i = 2; i <= n; i++){
        if (a[i - 1] >= 0 && a[i] >= 0){
            res += a[i] - a[i - 1];
            dem++;
            if (res > t) break;
        }
        if (a[i - 1] >= 0 && a[i] < 0){
            res += abs(a[i]) + a[i - 1];
            dem++;
            if (res > t) break;
        }
        if (a[i - 1] < 0 && a[i] < 0){
            res += abs(a[i]) - abs(a[i - 1]);
            dem++;
            if (res > t) break;
        }
        if (a[i - 1] < 0 && a[i] >= 0){
            res += a[i] + abs(a[i - 1]);
        dem++;
        if (res > t) break;
        }
    }
    cout << dem - 1;
    return 0;
}
