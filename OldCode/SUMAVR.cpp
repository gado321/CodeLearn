#include <iostream>

using namespace std;

const int N = (int) 1e5 + 1;

int n;

int main()
{
    cin >> n;
    static long long sum, res, x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        sum += res;
        res = x * i - sum;
        cout << res << " ";
    }
    return 0;
}
