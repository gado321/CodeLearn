#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n, k, a[1005];

int main()
{
    cin >> n >> k;
    static long long sum, x, y, SUM;
    for (int i = 1; i <= n; i++) {cin >> a[i]; sum += a[i];}
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; i++) {x += a[i]; y += a[n - i + 1];}
    if (abs(sum - x * 2) > abs(sum - y * 2)) cout << abs(sum - x * 2);
    else cout << abs(sum - y * 2);
    return 0;
}
