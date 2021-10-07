#include <bits/stdc++.h>

using namespace std;

int a[1000], n, R[1000], L[1000];

void traceLR()
{
	int top = 0; st[top] = 0;
	for (int i = 1; i <= n; i++)
	{
		while (top > 0 && a[st[top]] > a[i])
		{
			R[st[top]] = i - 1;
			top--;
		}
		if (a[i] != a[st[top]]) L[i] = st[top] + 1;
		else L[i] = L[st[top]];
		st[++top] = i;
		while (top > 0) R[st[top--]] = n;
	}
}

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	traceLR();
	for (int i = 1; i <= n; i++) cout << L[i] << " " << R[i] << endl;
	return 0;
}