#include <iostream>

using namespace std;

int a[1000], n, Max = 0;
int fi(int i)
{
    //int i = 1;
    Max = max(a[i],Max);
    if (i == n) return Max;
    else fi(i + 1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << fi(1);
    return 0;
}
