#include <iostream>
#include <fstream>
#define FOR(i, a, b) for (int i = 1; i <= n; i++)

using namespace std;

const int N = (int) 1e6 + 1;

int n, a[N];
long long m;
static long long sum;
int Max = 0;

int Find(int i, int j)
{
    int l = i, r = j;
    int ans = 0;
    while (l <= r)
    {
        long long res = 0;
        int mid = (l + r) / 2;
        FOR(i, 1, n)
            if (a[i] >= mid) res += (a[i] - mid);
        if (res >= m)
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

int main()
{
    //freopen("test.inp","r",stdin);
    cin >> n >> m;
    FOR(i, 1, n)
    {
        cin >> a[i];
        Max = max(Max,a[i]);
    }
    cout << Find(0,Max);
    return 0;
}
