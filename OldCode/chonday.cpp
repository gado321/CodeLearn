#include<iostream>
#include<fstream>
#include<stdio.h>
#include<algorithm>

using namespace std;
const int maxn=1e5+1000;
long n,a[maxn]={},dem=0;
long long b[maxn]={};
bool nhiphan(long l,long r,long x,long y)
{
    if(l>r) return 0;
    long mid=(l+r)/2;
    if(x-b[mid]==b[mid]+y) return 1;
    else if(x-b[mid]>b[mid]+y) return nhiphan(mid+1,r,x,y);
    else return nhiphan(l,mid-1,x,y);
}
int main()
{
    freopen("chonday.inp","r",stdin);
    freopen("chonday.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i]+b[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        long long x=b[i],y=b[n]-b[i];
        if(x==y) dem++;
        else if(x<y) continue;
        else
        {
            if(nhiphan(1,i-1,x,y))dem++;
        }
    }
    cout<<dem;
    return 0;
}