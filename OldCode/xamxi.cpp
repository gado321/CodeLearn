#include <iostream>
#include <fstream>

using namespace std;

int n, a[100][100];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i][j] == a[j][i]) res++;
    if (res == n * (n - 1) / 2) cout << "YES"; else cout << "NO";
    return 0;
}
