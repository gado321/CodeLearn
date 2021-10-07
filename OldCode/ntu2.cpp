#include <iostream>
#include <algorithm>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int N = (int) 1e5 + 1;

int a[N], n, k;

bool Find(int i, int j, int m)
{
    int l = i, r = j;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (m - k == a[mid]) return true;
        else if (m - k > a[mid]) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

int main()
{
    static int Count;
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    FOR(i, 1, n)
        if(Find(1, i, a[i]) == true) Count++;
    cout << Count;
    return 0;
}
