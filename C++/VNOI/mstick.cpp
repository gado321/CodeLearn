#include <iostream>
#include <algorithm>
#define fi first
#define se second

using namespace std;

typedef pair<int,int> ii;

ii a[5005];
int n;

bool cmp(ii a, ii b) {
    return ((a.fi < b.fi && a.se < b.se));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) cout << a[i].fi << " " << a[i].se << "\n";
    return 0;
}
