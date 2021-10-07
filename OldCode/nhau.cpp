#include <bits/stdc++.h>
using namespace std;
int n,d=0;
int x[11],c[11],cc[22],cp[22];
int kq[11][11];
void quaylui(int i)
{
	for(int j=1;j<=n;j++)
		if(!c[j] and !cc[i-j+n] and !cp[i+j])
		{
			c[j]=1;
			cc[i-j+n]=1;
			cp[i+j]=1;
			x[i]=j;
			if(i==n) 
			{
				for(int k=1;k<=n;k++) cout<<x[k]<<" ";
				cout<<endl;
				d++;
			} else quaylui(i+1);
			c[j]=0;
			cc[i-j+n]=0;
			cp[i+j]=0;
		}
}
int main()
{
	freopen("input.inp","r",stdin);
	cin>>n;
	memset(c,0,sizeof(c));
	memset(cc,0,sizeof(cc));
	memset(cp,0,sizeof(cp));
	quaylui(1);
	cout<<d<<endl;
}