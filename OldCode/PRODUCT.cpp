#include <iostream>
#include <fstream>

using namespace std;

long long a[100005];
long long b[100005];

int Find(long long a[], int n, int k)
{
    int l = 1, r = n, m, res = 0;
    while ( l <= r){
        m = ( l + r ) / 2;
        if ( a[m] <= k){
            l = m + 1;
            res = m;
        }
        else r = m - 1;
    }
    return res;
}

int main()
{
    freopen("product.inp", "r", stdin);
    freopen("product.out", "w", stdout);
    int n, k; long long tong = 0; cin >> n >> k;
    for ( int i = 1; i <= n; i++) { cin >> a[i]; tong += a[i]; }
    b[1] = a[1];
    for ( int i = 2; i <= n; i++) b[i] = b[i - 1] + a[i];
    //for ( int i = 1; i <= n; i++) cout << b[i] << " ";
    for ( int i = 1; i <= k; i++){
        long long c; cin >> c;
        int j = Find(a,n,c);
        cout << b[j] + (( n - j ) * c) << " ";
        //else cout << b[j - 1] + j + (( n - j ) * c) << " ";
    }
    return 0;
}
