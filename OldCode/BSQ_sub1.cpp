#include<iostream>
#include<algorithm>

using namespace std;
const int N= 3*1e5;
int a[ N ]= { 0 };
int main()
{
    int t; cin >> t;
    while( t-- ){
        int n, m, k; cin >> n >> m >> k;
            for( int i= 0; i < n; i++ ) cin >> a[ i ];
            int cnt= 0;
            for( int i= 0; i < n - 1; i++ )
                for( int j= i + 1; j < n; j++ ) cnt += ( abs( a[ i ] - a[ j ] ) <= k );

            cout << cnt << "\n";
        }
    return 0;
}
