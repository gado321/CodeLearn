#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair<int,int> ii;

ii a[5000], b[5000];
int n;

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i].fi >> b[i].se;
	}
	return 0;
}