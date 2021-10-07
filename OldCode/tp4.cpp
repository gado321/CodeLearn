#include <iostream>

using namespace std;

int m,n,k;

int main()
{
    cin>> n>> m >> k;
    int a = (m + n - k) / 3;
    int b = n / 2;
    a = min(a, b);
    a = min(a, m);
    cout << a;
}
