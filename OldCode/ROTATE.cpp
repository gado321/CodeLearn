#include <iostream>

using namespace std;

int main()
{
    float a, b, c, d, Max = -999999999;
    float A, B, D, C;
    static int dem;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> d;
    A = a / c - b / d;
    B = b / a - d / c;
    C = d / b - c / a;
    D = c / d - a / b;
    //cout << A << " " << B << " " << C << " " << D << " ";
    Max = max(A,Max); Max = max(B,Max); Max = max(C,Max); Max = max(D,Max);
    //cout << Max << endl;
    if (Max == A) cout << 0;
    else if (Max == B) cout << 3;
    else if (Max == C) cout << 2;
    else if (Max == D) cout << 1;
}
