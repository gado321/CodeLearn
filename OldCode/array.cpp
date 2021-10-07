#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int n;
long long tu, mau;

int main(int argc, char const *argv[])
{
	freopen("array.inp","r",stdin);
	freopen("array.out","w",stdin);
	cin >> n;
	tu = 1;
	mau = 1;
	for (int i = n + 1; i <= n * 2 - 1; i++) tu = ((tu % MOD) * (i % MOD)) % MOD;
	tu = ((tu % MOD) * (2 % MOD)) % MOD;
	for (int i = 2; i <= n - 1; i++) mau = ((mau % MOD) * (i % MOD)) % MOD;
	cout << tu / mau - n;
	return 0;
}