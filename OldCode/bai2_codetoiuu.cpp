#include <bits/stdc++.h>

using namespace std;

int a[10000], n, ans, tmp;
vector <int> adj;

int main(int argc, char const *argv[])
{
	cin >> n;
	ans = n - 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	adj.push_back(INT_MAX);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > adj.back())
		{
		while (a[i] > adj.back() && adj.size() > 0)
		{
			ans++;
			adj.pop_back();
		}
		adj.push_back(a[i]);
		}
		else if (a[i] < adj.back()) adj.push_back(a[i]);
		else if (a[i] == adj.back())
		{
			//tmp = 0;
			int t = adj.size() - 1;
			while (adj[t] == a[i] && t--) ans++;
			adj.push_back(a[i]);
			//cout << ans << " ";
		}
	}
	cout << ans << endl;
	return 0;
}