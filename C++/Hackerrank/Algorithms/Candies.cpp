#include <iostream>

using namespace std;

int n, tmp, a[100005], cnt[100005], can[100005];
long long ans;

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cnt[1] = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] > a[i - 1]) cnt[i] = cnt[i - 1] + 1;
        else cnt[i] = 1;
    ans = cnt[n];
    can[n] = cnt[n];
    for (int i = n - 1; i > 0; i--){
        if (a[i] > a[i + 1]) tmp = cnt[i + 1] + 1;
        else tmp = 1;
        ans += max(tmp,cnt[i]);
        can[i] = max(tmp,cnt[i]);
        cnt[i] = tmp;
    }
    for (int i = 1; i <= n; i++) cout << can[i] << " "; cout << endl;
    cout << ans;
    return 0;
}
