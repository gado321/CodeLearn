#include <iostream>

using namespace std;

int main()
{
    int m, n, k;
    cin >> n >> m >> k;
    int a = (m + n - k) / 3;
    int b = n / 2;
    a = min(a, b);
    a = min(a, m);
    cout << a;
}
