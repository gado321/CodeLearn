#include <iostream>

using namespace std;

int main()
{
    int n, Max = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        x += n - i;
        Max = max(Max, x);
    }
    cout << Max;
    return 0;
}
