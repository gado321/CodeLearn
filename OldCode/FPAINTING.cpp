#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int Max = -1, Min = 10000;
    Max = max(Max,a); Min = min(Min,a);
    Max = max(Max,b); Min = min(Min,b);
    Max = max(Max,c); Min = min(Min,c);
    Max = max(Max,d); Min = min(Min,d);
    if (b < c && a < d) cout << Max - Min - c + b;
    else if (c < a && d < a) cout << b - a + d - c;
    else cout << Max - Min;
}
