#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int a[10005], n;

string solve(int num , int i) {
    string tmp;
    num = (( num  % 101) + 101) % 101;
    if (i > n) {
        if (!num) return "";
        return "0";
    }
    else {
        tmp = solve(num * a[i], i + 1);
        if (tmp != "0") return "*" + to_string(a[i]) + tmp;
        tmp = solve(num + a[i], i + 1);
        if (tmp != "0") return "+" + to_string(a[i]) + tmp;
        tmp = solve(num - a[i], i + 1);
        if (tmp != "0") return "-" + to_string(a[i]) + tmp;
    }
    return "0";
}

int main() {
    //freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    string ans = to_string(a[1]) + solve(a[1],2);
    cout << ans;
    return 0;
}
