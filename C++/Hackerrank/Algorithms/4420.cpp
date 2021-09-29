#include <iostream>

using namespace std;

int n, a[30], sumAll, cnt, sum;
string s[2000000];
bool ok[30];

void check() {
    int tmp = 0;
    for (int i = 1; i <= n; i++) 
        if (ok[i]) tmp += a[i];
    if (tmp == sumAll / 2) {
        cnt++;
        for (int u = 1; u <= n; u++)
            if (!ok[u])
                s[cnt] += "A ";
            else
                s[cnt] += "B ";
    }
}

void back(int num) {
    for (int i = 0; i <= 1; i++) {
        if (!ok[num]) {
            ok[num] = i;
            if (num == n) check();
            else back(num + 1);
            ok[num] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sumAll += a[i];
    }
    if (sumAll % 2) {
        cout << "khong chia duoc";
        return 0;
    }
    back(1);
    if (!cnt) {
        cout << "khong chia duoc";
        return 0;
    }
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++) cout << s[i] << "\n";
    return 0;
}