#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //freopen("bai1.inp","r",stdin);
    //freopen("bai1.out","w",stdout);
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a + b + c == x + y) cout << "YES"; else cout << "NO";
    return 0;
}
