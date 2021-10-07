#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n, dem = 0;
int a[305];
bool check1 = 0, check2 = 0;

int main()
{
	cin >> t;
	for (int u = 1; u <= t; u++)
	{
		dem = 0;
		memset(a,0,sizeof(a) + 1);
		cin >> n;
		for (int j = 1; j <= n; j++) cin >> a[j];
		sort(a + 1, a + n + 1);
		//for (int j = 1; j <= n; j++) cout << a[j]; cout << endl;
		for (int i = 1; i <= n - 2; i++)
			for (int j = i + 1; j <= n - 1; j++)
			{
				for (int k = j + 1; k <= n; k++)
					if (a[i] + a[j] <= a[k]) break;
					else dem++;
			}
	cout << dem << endl;

	}
	return 0;
}