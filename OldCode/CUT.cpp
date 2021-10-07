#include <iostream>

using namespace std;

long long m, n, k;

int main()
{
    cin >> m >> n >> k;
    if (n == 1 && m == 1) cout << 1;
    else if (m == 1 && n != 1)
        {if (k > n - 1) cout << n; else cout << k + 1;}
    else if (n == 1 && m != 1)
        {if (k > m - 1) cout << m; else cout << k + 1;}
    else
    {
        long long dai, rong, cut, sum = 1;
        dai = max(m,n); rong = min(m,n);
        if (k / 2 < rong - 1 && k - k / 2 < dai - 1)
        {
            cut = k / 2;
            if (cut > rong - 1) sum *= rong; else sum *= (cut + 1);
            if (k - cut > dai - 1) sum *= dai; else sum *= (k - cut + 1);
        }
        else
        {
            cut = rong - 1;
            if (cut > rong - 1) sum *= rong; else sum *= (cut + 1);
            if (k - cut > dai - 1) sum *= dai; else sum *= (k - cut + 1);
        }
            cout << sum;
    }
    return 0;
}
