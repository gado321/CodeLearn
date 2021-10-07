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
            sort( a, a + n );
            int cnt= 0, j= 0;
            for( int i= 0; i < n;i++ ){
                while( j < n && a[j] - a[i] <=2 ) j++;
                j--;
                if(j-i>=2) cnt+=( (j-i)*(j-i-1))/2;
            }
            cout << cnt << "\n";
        }
}