#include <iostream>

using namespace std;

int t, n, y;
char x;

int main(int argc, char const *argv[])
{
	iosbase::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> x;
			if (x == 'L') y--;
			else y++;
		}
		cout << y << "\n";
	}
	return 0;
}