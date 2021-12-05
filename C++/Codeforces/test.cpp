#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int t, n, days;
int a[200005], ans, w[100005];
deque <int> q;

int check(int val, int days) {
    int sum = 0;
    days--;
    for (int i = 1; i <= n; i++) {
        if (sum + a[i] <= val) {
            sum += a[i];
        }
        else {
            sum = a[i];
            days--;
        }
    }
    return days >= 0;
}

int binary_searching(int l, int r) {
    int mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (check(mid,days) == 1) r = mid;
        else if (check(mid,days) == 0) l = mid + 1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> n >> days;
    int low = 0, high = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], high += a[i], low = max(low,a[i]);
    cout << binary_searching(low,high);
    return 0;
}
