#include <iostream>
#include <algorithm>
#include <fstream>
#define FOR(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

const int N = (int) 1e5 + 1;

int a[N], n, Max = 0;

int main()
{
    ios_base::sync_with_stdio; cin.tie(NULL);
    cin >> n;
    FOR(i, 1, n) {cin >> a[i]; Max = max(Max, a[i]);}
    sort(a + 1, a + n + 1);
    long long sum = 0;
    int dem = 0;
    FOR(i, 1, n)
    if (sum <= Max)
    {
        if (a[i] >= sum) dem++;
        else
        {
            int j = i + 1;
            while (a[i] < sum)
            {
                swap(a[i],a[j]);
                j++;
            }
            dem++;
        }
        sum += a[i];
    }
    else break;
    cout << dem;
    return 0;
}
