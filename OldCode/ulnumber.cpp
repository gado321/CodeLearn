#include <bits/stdc++.h>

using namespace std;

const long long oo = 1e9;

int n;
long long ans;
bool ok[1000000005];

void bfs(int x, int y) {
	queue <long long> q;
	q.push(x); ok[x] = 1;
	q.push(y); ok[y] = 1;
	while (!q.empty()) {
		int u = q.front();	
		if (u > n) return;
		q.pop();
		long long num1 = u * 10 + x;
		long long num2 = u * 10 + y;
		q.push(num1); 
		if (num1 <= oo) ok[num1] = 1;
		q.push(num2); 
		if (num2 <= oo) ok[num2] = 1;
	}
}

int main(int argc, char const *argv[])
{
	freopen("ulnumber.inp","r",stdin);
	freopen("ulnumber.out","w",stdout);
	cin >> n;
	for (int i = 0; i <= 9; i++) 
		for (int j = i + 1; j <= 9; j++) bfs(i,j);
	for (int i = 1; i <= n; i++) if (ok[i]) ans++;
	cout << ans;
	return 0;
}
