#include <iostream>

using namespace std;

int a, b, c, d, x, y;

int main()
{
    cin >> a >> b >> c >> x >> y;
    long long R1, R2, R3, res;
    R1 = a * x + b * y;
    int mi = min(x, y);
    int ma = max(x, y);
    int mod = max(x, y) - mi;
    R2 = c * mi * 2;
    if (x >= y) res = mod * a; else res = mod * b;
    R2 += res;
    R3 = c * ma * 2;
    //cout << R1 << " " << R2 << " " << R3;
    if (R1 <= R2 && R1 <= R3) cout << R1;
    else if (R2 <= R1 && R2 <= R3) cout << R2;
    else if (R3 <= R1 && R3 <= R2) cout << R3;
    return 0;
}
