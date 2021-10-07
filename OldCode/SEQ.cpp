#include <bits/stdc++.h>

using namespace std;

long long a[100005], c[100005];
int b[100005];

void qsort(int l, int r)
{
    int i = l, j = r;
    srand(time(NULL));  //khoi tao tham so ham rand()
    int m = a[l + rand() % (r-l+1)];
    //m = a[(l + r) / 2];
    while ( i <= j){
        while ( a[i] < m) i++;
        while ( a[j] > m) j--;
        if ( i <= j){
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            i++;
            j--;
        }
    }
    if (l < j) qsort(l,j);
    if (i < r) qsort(i,r);
}

int Search(int n, long long k)
{
    int l = 1, r = n, pos = 0;
    while ( l <= r){
        int m = (l + r) / 2;
        if ( a[m] >= k){
            r = m - 1;
            pos = b[m];
        }
        else l = m + 1;
    }
    return pos;
}

int main()
{
    freopen("SEQ.inp","r",stdin);
    //-freopen("SEQ.out","w",stdout);
    int n; long long k;
    cin >> n >> k;
    long long t = k;
    if ( k < 0 ) k = abs(k);
    for (int i = 1; i <= n; i++){ cin >> a[i]; b[i] = i; c[i] = a[i]; }
    qsort(1,n);
    for (int i = 1; i <= n; i++){
        int m = Search(n,k + a[i]);
        if ( m > 0 && m != b[i] )
        {
            if (c[m] <= c[b[i]] ) {
                swap(c[m],c[b[i]]);
                if ( c[m] - c[b[i]] == k ) { cout << m << " " << b[i]; break; }
                else swap(c[m],c[b[i]]);
            }
            else if ( c[m] - c[b[i]] == k && t < 0 ) { cout << b[i] << " " << m; break; }
            else if ( c[m] - c[b[i]] == k && t >= 0 ) { cout << m << " " << b[i]; break; }
        }
    }
    return 0;
}
