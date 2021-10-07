#include <iostream>
#include <fstream>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ll long long

using namespace std;

const int oo = (int) 1e7;

int a[1000], dp[1000], n;
int pos[1000];

int main()
{
    freopen("DCKGiam.inp","r",stdin);
    freopen("DCKGiam.out","w",stdout);
    cin >> n;
    int Max = 0;
    FOR(i,1,n) {cin >> a[i]; dp[i] = 1;}
    a[n + 1] = oo;
    FOR(i,2,n + 1)
        for (int j = i - 1; j >= 1; j--)
            if (a[i] > a[j])
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    if (dp[i] > Max) {Max = dp[i]; pos[i] = j;}
                }
    //cout << --Max << "\n";
    FOR(i,1,n + 1)
        if(pos[i]) cout << a[pos[i]] << " ";
    return 0;
}
