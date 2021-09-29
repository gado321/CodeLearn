#include <bits/stdc++.h>

using namespace std;

int x, n, ans, pre, sum;
bool ok[40];

int Pow(int n, int k) {
    if (n == 0) return 0;
    if (n == 1 || !k) return 1;
    if (k == 1) return n;
    return n * Pow(n, k - 1);
}

void powSum(int x, int k) {
    while (k <= 31) {
        sum += Pow(k,n);
        if (sum < x) powSum(x,k + 1);
        else if (sum == x) ans++;
        sum -= Pow(k,n);
        k++;
    }
}

int main() {
    freopen("test.inp","r",stdin);
    cin >> x >> n;
    powSum(x, 1);
    cout << ans;
    return 0;
}
