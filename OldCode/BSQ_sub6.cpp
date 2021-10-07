#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;

long long t,n,a[200010],m,k,C[200010][110];
int main()
{
    freopen("BSQ.inp","r",stdin);
    freopen("BSQ.out","w",stdout);
    C[0][0]=1;
    for(int i=1;i<=200000;i++)
    {
        for(int j=0;j<=min(i,100);j++)
        {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        cin>>n>>m>>k;

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            long long vt=upper_bound(a+i+1,a+n+1,a[i]+k)-a;
            long long tam=vt-i-1;
            ans=(ans+C[tam][m-1])%MOD;

        }
        cout<<ans%MOD<<endl;
    }
    return 0;
}
