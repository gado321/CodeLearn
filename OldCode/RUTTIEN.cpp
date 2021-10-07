#include <iostream>

using namespace std;

int main()
{
    int n, k, i;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (k - x >= 0) {k -= x; cout << 1;} else cout << 0;
        if (k <= 0) break;
    }
    for (int j = i + 1; j <= n; j++) cout << 0;
    return 0;
}
