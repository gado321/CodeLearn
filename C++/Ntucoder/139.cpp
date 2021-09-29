#include <iostream>
#include <stack>

using namespace std;

int n, ok[50], ans, tmp;

bool check() {
    stack <int> st;
    for (int i = 1; i <= n; i++)
        if (ok[i] == 2) st.push(1);
        else {
            if (st.size()) st.pop();
            else return 0;
        }
    if (!st.size()) {
        for (int i = 1; i <= n; i++)
            if (ok[i] == 2) cout << "(";
            else cout << ")";
        return 1;
    }
    return 0;
}

void back(int num) {
    for (int i = 2; i >= 1; i--) {
        if (!ok[num]) {
            ok[num] = i;
            if (i == 2) tmp++;
            if (num == n || tmp == n / 2) {
                if (check()) {
                    ans++;
                    cout << "\n";
                }
            }
            else back(num + 1);
            ok[num] = 0;
            if (i == 2) tmp--;
        }
    }
}

int main() {
    cin >> n;
    back(1);
    cout << ans;
    return 0;
}