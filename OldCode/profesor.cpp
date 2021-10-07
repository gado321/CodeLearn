#include<bits/stdc++.h>
using namespace std;
long long n,dp[100010][3],ok[10];
typedef pair <int,int> ii;
ii a[100010];
int main()
{
    freopen("PROFESOR.inp","r",stdin);
    freopen("PROFESOR.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    if(n==1)
    {
        cout<<"1 "<<min(a[1].first,a[1].second)<<endl;
        return 0;
    }
    for(int i=1;i<=5;i++)
    {
        long long ans=1,ma=INT_MAX,dem=1;
        for(int j=1;j<n;j++)
        {
            if((a[j].first==a[j+1].first&&a[j].first==i)||(a[j].first==a[j+1].second&&a[j].first==i)||(a[j].second==i&&a[j].second==a[j+1].first)||(a[j].second==i&&a[j].second==a[j+1].second))
            {
                dem++;
                ans=max(dem,ans);
            }
            else dem=1;
        }
        ok[i]=ans;
       // cout<<ans<<" "<<i<<endl;
    }
long long    Ma=INT_MIN;
    for(int i=1;i<=5;i++)
    {
        if(Ma<ok[i]) Ma=ok[i];
    }
    for(int i=1;i<=5;i++)
    {
        if(Ma==ok[i])
        {
            cout<<Ma<<" "<<i;
            return 0;
        }
    }
    //if(ans==1) cout<<"0 0"<<endl;
    return 0;
}