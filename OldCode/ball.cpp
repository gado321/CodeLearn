#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const double oo = 1e8;

struct point
{
	int id;
	double h; 
};
int n, k, p, q;
long x[2005], y[2005];
point pi[2005];

bool find(point *pi,int l,int r,int &p,int &q) 
{
	if (l >= r) return 0;
	swap(pi[l],pi[(l + r) / 2]);
	int i = l;
	for (int j = l + 1; j <= r; j++)
	{
		if (pi[l].h == pi[j].h) 
		{
			p = l; 
			q = j; 
			return 1;
		}
		if (pi[j].h < pi[l].h) 
		{
			i++; 
			swap(pi[i],pi[j]);
		}
	}
	if (find(pi,l + 1,i,p,q)) return 1;
	if (find(pi,i + 1,r,p,q)) return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	//freopen("ball.inp","r",stdin);
	cin >> n;
	k = 2 * n;
	for (int i = 1; i <= k; i++) cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = n + 1; j <= k; j++)
		{
			if(x[i] == x[j]) pi[j].h = oo; else pi[j].h = double(y[j]-y[i])/(x[j]-x[i]);
			pi[j].id = j;
		}
		if (find(pi,n + 1,k,p,q)) 
		{
			printf("%d %d %d",pi[q].id,pi[p].id,i); 
			return 0;
		}
	}
	for (int i = n + 1; i <= k; i++)
	{
		for (int j = 1;j <= n; j++)
		{
			if(x[i] == x[j]) pi[j].h = oo; else pi[j].h = double(y[j]-y[i])/(x[j]-x[i]);
			pi[j].id = j;
		}
		if (find(pi,1,n,p,q)) 
		{
			printf("%d %d %d",pi[q].id,pi[p].id,i); 
			return 0;
		}
	}
	cout << -1;
}