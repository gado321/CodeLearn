#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long n;
int k, z;
int trace[50], ans[50], a[21];

bool cmp(int a, int b) {
    return a > b;
}

void check() {
    bool ok = 0;
    for (int i = 1; i <= 31; i++) {
        if (trace[i] < ans[i]) {ok = 1; break;}
    }
    if (ok) {
        for (int i = 1; i <= 31; i++) ans[i] = trace[i];
    }
}

void back(int num, int c) {
    if (z == 1) return;
    for (int i = 1; i <= k; i++) {
        if (num % a[i] == 0) {
            trace[c] = num;
            num = num / a[i];
            if (num == 1) {
                z = 1;
                trace[c + 1] = 1;
                check();
            }
            else back(num,c + 1);
            num *= a[i];
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> a[i];
    sort(a + 1, a + k + 1, cmp);
    memset(ans,100,sizeof(ans));
    back(n,1);
    if (!z) cout << -1;
    else {
        for (int i = 31; i > 0; i--)
            if (ans[i]) cout << ans[i] << " ";
    }
    return 0;
}