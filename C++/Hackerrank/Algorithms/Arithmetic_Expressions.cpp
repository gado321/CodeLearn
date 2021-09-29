#include <bits/stdc++.h>

using namespace std;

int n, a[100000];
string s;

int solve(string ans,int num, int i) {
    if (i > n) {
        if (!num) cout << s;
        return 1;
    }
    else {
        if (solve(ans + "+" + to_string(a[i]),(num + a[i]) % 101,i)) return 1;
        if (solve(ans + "-" + to_string(a[i]),(num - a[i]) % 101,i)) return 1;
        if (solve(ans + "*" + to_string(a[i]),(num * a[i]) % 101,i)) return 1;
    }
    return 0;
} 

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int tmp = solve(to_string(a[1]),a[1],2); 
}