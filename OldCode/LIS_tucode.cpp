#include <bits/stdc++.h>

using namespace std;

const long long oo = 100000000000000005;

vector <int> res;
int a[100000], f[100000], n, m;
long long Max = -oo, Min = oo, pos_max, pos_min;

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
		if (Max < f[i]) Max = f[i], pos_max = i;
	for (int i = 1; i <= pos_max; i++)
		if (Min > f[i]) Min = f[i], pos_min = i;
	cout << Max - Min << endl;
	for (int i = pos_min; i <= pos_max; i++) cout << a[i] << " ";
	return 0;
}