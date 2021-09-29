#include <bits/stdc++.h>

using namespace std;

long long m, a[1005], ans;
int n, q;

bool cmp(int a, int b) {
    return a > b;
}

long long solve(long long amount) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (amount % a[i] == 0 && amount != a[i]) {
            ans = max(ans,solve(a[i]) * (amount / a[i]) + 1);
        }
    }
    return ans;
}

int main() {
    freopen("test.inp","r",stdin);
    cin >> q;
    while (q--) {
        cin >> m >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1,cmp);
        cout << solve(m) << endl;
    }
    return 0;
}
