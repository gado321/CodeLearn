#include <iostream>

using namespace std;

int main()
{
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    static int A, X;
    if (a >= b && a >= c) {A = a; a = 0;}
    else if (b >= a && b >= c) {A = b; b = 0;}
    else if (c >= b && c >= a) {A = c; c = 0;}
    if (x >= y && x >= z) {X = x; x = 0;}
    else if (y >= x && y >= z) {X = y; y = 0;}
    else if (z >= x && z >= y) {X = z; z = 0;}
    cout << a + b + c + x + y + z + max(A,X) - min(A,X);
}
