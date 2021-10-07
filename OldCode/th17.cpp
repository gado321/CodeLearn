#include <iostream>

using namespace std;

int a[10000], n;

int main()
{
    static int x, y, z;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0) x++;
        else if (a[i] > 0) y++;
        else if (a[i] < 0) z++;
    }
    cout << x << " " << y << " " << z;
    return 0;
}
