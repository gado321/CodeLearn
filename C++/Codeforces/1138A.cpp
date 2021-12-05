#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int n, a[100005], s1, s2, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = a[1];
    a[n + 1] = 3;
    for (int i = 1, j = 1; i <= n + 1; ++i) {
        if (a[i] == a[i - 1]) s1++;
        else {
            ans = max(min(s1,s2) * 2,ans);
            s2 = s1;
            s1 = 1;
        }
    }
    cout << ans;
    return 0;
}
