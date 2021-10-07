#include <bits/stdc++.h>

using namespace std;

int n, k, t, l, r, maxi, x;
int a[10000], sum, tmp;

queue <int> q;

int main(int argc, char const *argv[])
{
	cin >> n >> t;
	for (int i = 1; i < n; i++) q.push(i);
	//cout << n << " ";
	k = --n; x = 1;
	tmp = 0;
	while (!q.empty())
	{
		int b = q.front();
		tmp += b;
		if (k * x - tmp < t) 
		{
			if (!a[b]) cout << b << " "; 
			x++; q.pop();
		}
		else if (k * x - tmp > t) 
		{
			cout << k << " ";
			a[k] = 1;
			t -= (tmp + k);
			cout << k * x - tmp << endl; 
			tmp = 0; 
			--k; 
			x = 1;
		}
		if (t <= 0) break;
	}
	return 0;
}