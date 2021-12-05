#include <bits/stdc++.h>

using namespace std;

int n, x[1000005], y[1000005], ans = -1e8, xx = 1e8, yy = 1e8;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    for (int i = 1; i <= n; ++i) {
        long long tmp = 0;
        for (int j = 1; j <= n; ++j) {
            //if (i != j)
            {
                tmp += abs(x[i] - x[j]) + abs(y[i] - y[j]);
            }
        }
        if (ans < tmp) {
            ans = tmp;
            //cout << x[i] << " " << y[i] << endl;
            xx = x[i];
            yy = y[i];
        }
        /*else if (ans == tmp) {
            if (x[i] < xx) {
                xx = x[i];
                yy = y[i];
            }
            else if (x[i] == xx && y[i] < yy) {
                xx = x[i];
                yy = y[i];
            }
        }*/
    }
    cout << ans << endl;
    cout << xx << " " << yy;
    return 0;
}
