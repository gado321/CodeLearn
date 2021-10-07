#include <iostream>
#include <vector>

using namespace std;

int d, k, cnt;
long long tmp;
int number[105];

int main(int argc, char const *argv[])
{
	cin >> d >> k;
	number[0] = d;
	tmp = d * k;
	for (int i = 1; i <= 105; i++) {
		number[++cnt] = tmp % 10;
		tmp = (tmp % 10) * k + tmp / 10;
		if (tmp == d) break;
	}
	if (!number[cnt]) {
		cout << - 1;
		return 0;
	}
	for (int i = cnt; i >= 0; i--) cout << number[i];
	return 0;
}