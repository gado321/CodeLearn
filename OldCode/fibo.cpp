#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int N = 9 * 1e7;

long long f[N + 1], n;

int main()
{
    //cin >> n;
    freopen("test.out","w",stdout);
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= N; i++) f[i] = f[i - 1] + f[i - 2];
    for (int i = 1; i <= N; i++) cout << f[i] << "\n";
}
