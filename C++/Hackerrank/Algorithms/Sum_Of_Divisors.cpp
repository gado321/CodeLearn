#include <iostream>
#include <math.h>

using namespace std;

long long n, ans;

int main()
{
    cin >> n;
    for (long long i = 1; i <= sqrt(n); ++i)
    {
        long long sum1 = i * (n / i - i + 1);
        long long sum2 = (n / i) * (n / i + 1) / 2 - i * (i + 1) / 2;
        ans += sum1 + sum2;
    }
    cout << ans;
    return 0;
}