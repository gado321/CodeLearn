#include <iostream>

using namespace std;

long long n, a, b;
long long ans;

int main(int argc, char const *argv[])
{
	freopen("onum.inp","r",stdin);
	freopen("onum.out","w",stdout);
	cin >> n >> a >> b;
	if (a > b) {cout << 0; return 0;}
	ans = (b - a) * (n - 2) + 1;
	cout << ans;
	return 0;
}