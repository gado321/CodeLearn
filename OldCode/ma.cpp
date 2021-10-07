#include <bits/stdc++.h>
using namespace std;
int r[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int c[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int a[20][20], x, y;
int d=1,n;
void nghiem()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
	exit(0);
}
void ma(int x, int y)
{
	//cout<<d<<" "<<x<<" "<<y<<endl;
	for(int j=0;j<8;j++)
	{
		int xx=x+r[j];
		int yy=y+c[j];
		if(xx<=n and yy<=n and xx>0 and yy>0 and a[xx][yy]==0)
		{
			d++;
			a[xx][yy]=d;
			if(d==n*n) nghiem();
			 else ma(xx,yy);
			d--;
			a[xx][yy]=0;
		}
	}
}
int main()
{
	//freopen("input.inp","r",stdin);
	cin>>n >> x >> y;
	memset(a,0,sizeof(a));
	a[x][y]=1;
	ma(x,y);
}
