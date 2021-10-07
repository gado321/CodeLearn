#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float a, b, c, d, Max = -999999999;
    float A = -999999999, B = -999999999, D = -999999999, C = -999999999;
    static int dem;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> d;
    A = a / c - b / d;
    B = b / a - d / c;
    C = d / b - c / a;;
    D = c / d - a / b;
    cout << A << " " << B << " " << C << " " << D << " ";
    Max = max(A,Max); Max = max(B,Max); Max = max(C,Max); Max = max(D,Max);
    cout << Max << endl
    cout << Max << endl;
    if (Max == A) cout << 1;
    else if (Max == B) cout << 2;
    else if (Max == C) cout << 3;
    else if (Max == D) cout << 4;
}
