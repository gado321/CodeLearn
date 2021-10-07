#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	freopen("delstr.inp","r",stdin);
	//freopen("delstr.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		d[(int)a[i]]++;
	}
	
	return 0;
}