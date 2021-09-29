#include <iostream>

using namespace std;

int a[30], ok[30], n, m, cnt = 1;

void back(int k)
{
    for (int i = 1; i <= m; i++) {
        //if (!ok[i]) {
            a[k] = i;
            //ok[i] = 1;
            if (k == n) {
                for (int j = 1; j <= n; j++)
                    cout << a[j];
                cout << "\n";
            }
            else
                back(k + 1);
            //ok[i] = 0;
        //}
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cnt *= m;
    cout << cnt << "\n";    
    back(1);
    return 0;
}