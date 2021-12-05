// a^b mod m = a^(b/2) * a^(b/2) * a^(b mod 2)
// DPT: O(log(b))

#include <iostream>

using namespace std;

long long a, b, m;

long long Power(long long a, long long b, long long m) {
    if (!b) return 1 % m;
    long long ans = Power(a, b / 2, m);
    ans = ans * ans % m;
    if (b % 2 == 1) ans = ans * a % m;
    return ans;
}

int main() {
    cin >> a >> b >> m;
    cout << Power(a,b,m);
    return 0;
}
