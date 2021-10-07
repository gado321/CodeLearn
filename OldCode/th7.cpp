#include <iostream>

using namespace std;

int a, b;

int GCD(int a, int b)
{
    if (b == 0) return a;
    if (a >= b && b != 0) return GCD(a % b, b);
    if (a < b && b != 0) return GCD(b, a);
}

int main()
{
    cin >> a >> b;
    cout << GCD(a,b) << " ";
    cout << (a * b) / GCD(a,b);
    return 0;
}
