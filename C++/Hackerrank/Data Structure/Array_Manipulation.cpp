#include <iostream>
#include <math.h>

using namespace std;

int n, m;
long long maxi = -1e17;
long long a[10000005], pos[10000005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        pos[u] += w; 
        pos[v + 1] += -w;
    }
    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + pos[i];
    for (int i = 1; i <= n; i++) maxi = max(maxi,a[i]);
    cout << maxi;
}