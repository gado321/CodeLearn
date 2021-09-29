#include <iostream>

using namespace std;

int a[1005];
int ans, n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            ans++;
            for (int j = i + 1; j <= n; j++)
                if (a[i] == a[j]) a[j] = 0;
                else if (a[i] > a[j]) break;
        }
    }
    cout << ans;
    return 0;
}