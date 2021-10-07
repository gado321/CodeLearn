#include <iostream>
#include <cmath>
using namespace std;

int a, b, c, d;

int main()
{
    cin >> a >> b >> c >> d;
    static int x, y, f, e, z, kq;
    kq=0;
    x = a % 2;
    y = c % 2;
    z = min(b, d);
    if (b - z > 0)
    {
        e=b - z - y;
        b=b - z - y;
        c=0;
    }
    else
        c=y;
    if (d - z > 0)
    {
        f = d - z - x;
        d = d - z - x;
        a = 0;
    }
    else
        a= x;
    if ((a==1) && (b>0)) e--;
    if ((c==1) && (d>0)) f--;
    kq = x + y + e + f;
    cout << kq;
}
