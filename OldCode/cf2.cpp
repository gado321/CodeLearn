#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int N = 200000;

int a[N + 5], save[N + 5], n, k;

bool check(int x)
{
    int sum = 0;
    for(int i = 1; i <= N; i++) sum += save[i] / x;
    if(sum >= k) return true;
    return false;
}
int main()
{
    freopen("cf1.inp","r",stdin);
    cin >> n >> k;
    memset(save, 0, N);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        save[a[i]]++;
    }
    int l = 1, r = n;
    while(l + 1 <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid) == true) l = mid;
        else r = mid;
    }
    if(check(r) == true) l = r;
    static int temp1;
    for(int i = 1; i <= N; i++)
    {
        int temp2 = save[i] / l;
        if (temp2)
        {
            if (temp1 + temp2 >= k)
            {
                temp2 = k - temp1;
                for(int j = 1; j <= temp2; j++) cout << i << " ";
                break;
            }
            else
            {
                for(int j = 1; j <= temp2; j++) cout << i << " ";
                temp1 += temp2;
            }
        }
    }
    return 0;

}


/*#include<iostream>
#include<stdio.h>
#include <fstream>
using namespace std;
int A[200010],B[200010],u;
int f(int k){
    int i,sum=0;
    for(i=1;i<=200000;i++) sum+=B[i]/k;
    if(sum>=u) return 1;
    else return 0;
}
int main(){
    freopen("cf1.inp","r",stdin);
    int i,n;
    scanf("%d%d",&n,&u);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        B[A[i]]++;
    }
    int l=1,r=n;
    while(l+1<r){
        int mid=(l+r)/2;
        if(f(mid)) l=mid;
        else r=mid;
    }
    if(f(r)) l=r;
    int y=0,j;
    for(i=1;i<=200000;i++){
        int x=B[i]/l;
        if(x){
            if(x+y>=u){
                x=u-y;
                for(j=1;j<=x;j++) printf("%d ",i);
                break;
            }
            else{
                for(j=1;j<=x;j++) printf("%d ",i);
                y+=x;
            }
        }
    }
    return 0;

}*/

