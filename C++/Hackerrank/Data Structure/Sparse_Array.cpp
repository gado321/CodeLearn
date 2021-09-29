#include <iostream>

using namespace std;

string a[1005], b[1005];
int n, q, cnt[1005];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    for (int i = 1; i <= q; i++) cin >> b[i];
    for (int i = 1; i <= q; i++)
        for (int j = 1; j <= n; j++)
            if (b[i] == a[j]) cnt[i]++;
    for (int i = 1; i <= q; i++) cout << cnt[i] << "\n";
    return 0;
}