#include <bits/stdc++.h>

using namespace std;

float p, tmp;
long long sum, ans;

int main(int argc, char const *argv[])
{
	cin >> p;
	int cnt = 1;
	while (p * cnt != (long long)(p * cnt)) cnt++;
	cout << cnt << endl;
	sum = p;
	cnt = 5;
	while (sum > 0) {
		if (sum / cnt > 0) {ans += sum / cnt; sum -= ans * cnt;}
		else cnt--;
	}
	cout << ans;
	return 0;
}