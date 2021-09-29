#include <iostream>

using namespace std;

int n, tmp, a[100005], cnt[100005];
long long ans;

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; i++)
        if (a[i] > a[i - 1]) cnt[i] = cnt[i - 1] + 1;
        else cnt[i] = 1;
    ans = cnt[n];
    for (int i = n - 1; i > 0; i++){
        if (a[i] > a[i + 1]) tmp = cnt[i + 1] + 1;
        else cnt[i] = 1;
        ans += max(tmp,cnt[i]);
        cnt[i] = tmp;
    }
    cout << ans;
    return 0;
}
