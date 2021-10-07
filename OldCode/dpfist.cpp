
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int dp[1000], pos[1000], n;

struct day{
    int value;
    int dp;
};

bool tmp(day a, day b)
{
    return a.value < b.value;
}

day a[10000];

int main()
{
    freopen("test.inp","r",stdin);
    cin >> n;
    a[0].dp = 0;
    FOR(i, 1, n) {cin >> a[i].value; a[i].dp = 1;}
    FOR(i, 2, n)
     for (int j = i - 1; j >= 1; j--)
        if (a[i].value > a[j].value)
            a[i].dp = max(a[j].dp + 1,a[i].dp);
    static int res;
    sort(a + 1, a + n + 1, tmp);
    //FOR(i, 1, n) cout << a[i].value << " "; cout << endl;
    //FOR(i, 1, n) cout << a[i].dp << " "; cout << endl;
    FOR(i, 1, n) res = max(res,a[i].dp);
    cout << res << "\n";
    FOR(i, 1, n)
    {
        if (a[i].dp < a[i + 1].dp && a[i].value != a[i + 1].value)
        {
            cout << a[i].value << " ";
            res--;
        }
        else if (a[i].dp >= a[i + 1].dp && a[i].value != a[i + 1].value)
        {
            cout << a[i].value << " ";
            res--;
            i++;
        }
        if (res == 0) break;
    }
    return 0;
}
