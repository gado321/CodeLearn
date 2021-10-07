#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, l, m, n, d, a[100005],tmp = 0;
    cin >> k >> l >> m >> n >> d;
    //memset(a,0,100005);
    for (int i = 1; i <= d; i++)
    {
        if (i % k == 0) tmp++;
        else if (i % l == 0) tmp++;
        else if (i % m == 0) tmp++;
        else if (i % n == 0) tmp++;
    }
    cout << tmp;
    return 0;
}
