#include<bits/stdc++.h>

using namespace std;

int n, a[500005], cnt[500005], dem;
bool check = 0;

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			check = 1;
			for (int k = i; k <= j; k++)
			{
				cnt[a[k]]++;
				if (cnt[a[k]] > 2) {check = 0; break;}
			}
			cout << i << " " << j << endl;
			memset(cnt,0,sizeof(cnt));
			if (check) dem++;
			else break;
		}
	cout << dem;
	return 0;
}

