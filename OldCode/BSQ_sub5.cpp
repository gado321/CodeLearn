#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
long long t,n,m,k,a[21],giaithua[21];
int main()
{
     freopen("BSQ.inp","r",stdin);
    freopen("BSQ.out","w",stdout);
    giaithua[0]=1;//O(1)
    for(int i=1;i<=20;i++) //o(20)
    {
        giaithua[i]=giaithua[i-1]*i; //O(2)
    }
    //cout<<giaithua[20]<<endl;
    cin>>t;//O(1)
    for(int x=1;x<=t;x++) //O(t)
    {
        cin>>n>>m>>k;//O(3)
        for(int i=1;i<=n;i++)//O(n)
        {
            cin>>a[i];//O(1)
        }
        sort(a+1,a+n+1);//O(nlogn)
        long long ans=0;//O(1)
        for(int i=1;i<=n;i++)//O(n)
        {
            long long vt=upper_bound(a+i+1,a+n+1,a[i]+k)-a; //O(logn)
            long long tam=vt-i-1;//O(2)
            if(m-1>tam) continue; //O(4)
            ans=(ans+(giaithua[tam]/(giaithua[m-1]*giaithua[tam-m+1]))%MOD)%MOD;//O(6)
        }
        cout<<ans<<endl;//O(1)
    }
    //Do hieu qua: 1+20*2+1+t*(3+n*1+nlogn+1+n*(logn+2+4+6))+1
    return 0;
}