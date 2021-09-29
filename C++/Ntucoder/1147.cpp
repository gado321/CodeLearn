#include <iostream>

using namespace std;

int n, m, w[25], val[25], f[25][105];

void trace(int i, int j){
    if (!f[i][j]) return;
    while (f[i][j] - val[i] != f[i - 1][j - w[i]]) i--;
    cout << i << " ";
    trace(i - 1, j - w[i]);
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i] >> val[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            if (w[i] > j) f[i][j] = f[i - 1][j];
            else 
                f[i][j] = max(f[i - 1][j],f[i - 1][j - w[i]] + val[i]);
        }
    cout << f[n][m] << endl;
    trace(n, m);
    return 0;
}