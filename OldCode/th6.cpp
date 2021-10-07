#include <iostream>

using namespace std;

long long gt(int n)
{
    if (n == 0) return 1;
    if (n == 1) return n;
    return n * gt(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << gt(n);
    return 0;
}
