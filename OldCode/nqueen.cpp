#include <bits/stdc++.h>

using namespace std;

int n, ans;
int cc[50], cp[50], ok[50];

void bachtrach(int i)
{
	for (int j = 1; j <= n; j++)
		if (!ok[j] && !cc[i - j + n] && !cp[i + j])
		{
			ok[j] = 1;
			cc[i - j + n] = 1; 
			cp[i + j] = 1;
			if (i == n) ans++;
			else bachtrach(i + 1);
			ok[j] = 0;
			cc[i - j + n] = 0; 
			cp[i + j] = 0;
		}
}

int main(int argc, char const *argv[])
{
	cin >> n;
	bachtrach(1);
	cout << ans;
	return 0;
}