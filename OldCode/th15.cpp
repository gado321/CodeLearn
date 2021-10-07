#include <iostream>

using namespace std;

int main()
{
    int n, m;
    static int dem;
    cin >> n >> m;
    while (n < m * 1000)
    {
        n *= 2;
        dem++;
    }
    cout << dem;
    return 0;
}
