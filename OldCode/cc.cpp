#include <iostream>
using namespace std;
int main ()
{
    int n, m;
    int sum = 1, dem = 0;
    int s;
    int mang[10005];
    cin >> n >> m;
    int i = 0;
    for ( int i = 0; i < n; i++){
        cin >> mang[i];
    }
    for ( int k = 0; k < n; k++ ){
        for ( int j = 0; j < n-1; j ++ ){
            if ( mang[j] > mang[k]){
                s = mang[j];
                mang[j] = mang[k];
                mang[k] = s;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (sum - m >= 0)
        {
            cout << dem;
            break;
        }
        sum = sum + mang[i] - 1;
        dem++;
        if (i == 0) cout << -1;
    }
    return 0;
}
