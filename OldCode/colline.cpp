#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[11], b[11], ak[11], bk[11], ns, ms, aa, bb;

int main(int argc, char const *argv[])
{
	//freopen("collide.inp","r",stdin);
    //freopen("collide.out","w",stdout);
	cin >> n >> m;
	for (int i = 10; i > 0; i--) 
	{
		if (n) ns++;
		if (m) ms++;
		a[i] = n % 10;
		b[i] = m % 10;
		n /= 10;
		m /= 10;
	}
	for (int i = 10; i > 10 - max(ns,ms); i--)
	{
		if (a[i] > b[i]) ak[i] = 1;
		else if (a[i] < b[i]) bk[i] = 1;
		else {bk[i] = 1; ak[i] = 1;}
	}
	for (int i = 1; i <= 10; i++) 
		if (ak[i]) aa = aa * 10 + a[i]; 
	for (int i = 1; i <= 10; i++) 
		if (bk[i]) bb = bb * 10 + b[i];
	cout << aa << endl << bb;
	return 0;
}