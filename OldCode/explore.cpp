#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int a[50005];

int main()
{
    freopen("explore.inp","r",stdin);
    //freopen("explore.out","w",stdout);
    long long t; int n;
    cin >> t >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    int res = abs(a[1]), dem = 1;
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
