#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{

    freopen("BSQ07.inp","w",stdout);
    srand(time(NULL));
    t=rand()%10+1;
    cout<<t<<endl;
    for(int x=1;x<=t;x++)
    {
        int n=rand()%(1000 - 2) + 1;
        int m=2;
        int k=rand()%n+1;
        if(m>n) swap(n,m);
        //m=min(m,4);
        cout<<n<<" "<<m<<" "<<k<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<rand()%250<<" ";
        }
        cout<<endl;
    }
    return 0;
}