#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) m += (m * k / 100);
    cout << m;
    return 0;
}
