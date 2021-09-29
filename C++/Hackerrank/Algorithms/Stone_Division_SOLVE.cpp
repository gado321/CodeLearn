#include <bits/stdc++.h>

using namespace std;

long long m, a[1005], ans[1005];
int n, q, nn;

int main() {
    //freopen("test.inp","r",stdin);
    cin >> q;
    while (q--) {
        n = 0;
        cin >> m >> nn;
        for (int i = 1; i <= 1000; i++) ans[i] = 0;
        for (int i = 1; i <= nn; i++) {
            long long tmp = 0;
            cin >> tmp;
            if (tmp < m) a[++n] = tmp;
        }
        sort(a + 1, a + n + 1);
        a[++n] = m;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (a[j] % a[i] == 0)
                    ans[j] = max(ans[j],ans[i] * (a[j] / a[i]) + 1);
        cout << ans[n] << endl;
    }
    return 0;
}
