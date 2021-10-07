#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
long long t,n,a[200010], m , k;
int main()
{
	freopen("BSQ.inp","r",stdin);
    freopen("BSQ.out","w",stdout);
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        cin>>n >> m >> k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            long long vt=upper_bound(a+i+1,a+n+1,a[i]+2)-a;
            long long tam=vt-i-1;
            ans=(ans+(tam*(tam-1)/2)%MOD) % MOD;

        }
        cout<<ans % MOD<<endl;
    }
    return 0;
}