#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int mi = 1000000;
    for (int i = 1; i <= n / 2; i++)
        if (a[i] + a[n - i + 1] <= mi) mi = a[i] + a[n - i + 1];
    cout << mi;
    return 0;
}
