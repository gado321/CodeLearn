#include <iostream>
#include <fstream>

using namespace std;

int pos[2005];
string a[20], correctPass, temp;
int t, n, cnt;
bool ok;

bool check(string x, string y) {
    if (x.size() > y.size()) return 0;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] != y[i]) return 0;
    }
    return 1;
}

void checkPass(int len) {
    for (int i = 1; i <= n; ++i) {
        if (ok) return;
        if (check(temp + a[i],correctPass)) {
            temp += a[i];
            pos[len] = i;
            if (temp == correctPass && !ok) {
                for (int j = 1; j < len; j++) cout << a[pos[j]] << " ";
                cout << a[pos[len]] << endl;
                ok = 1;
            }
            cnt++;
            if (!ok && cnt <= 10000) checkPass(len + 1);
            temp.erase(temp.size() - a[i].size(), a[i].size());
        }
    }
}

int main() {
    //freopen("test.inp","r",stdin);
    cin >> t;
    while (t--) {
        temp = ""; cnt = 0; ok = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cin >> correctPass;
        checkPass(1);
        if (!ok) cout << "WRONG PASSWORD\n";
    }
    return 0;
}
