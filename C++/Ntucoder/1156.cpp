#include <bits/stdc++.h>

using namespace std;

const int mod = 10000;

long long n;
int x;

int power(int a, long long b) {
    int tmp = 1;
    for (int i = 1; i <= b; i++)
    tmp = ((tmp % mod) * (a % mod)) % mod;
    return tmp;
}

int main() {
    cin >> x >> n;
    cout << power(x % mod,n % mod);
    return 0;
}