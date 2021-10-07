#include <bits/stdc++.h>

using namespace std;

int n, m, xa, ya, xb, yb;

int main(int argc, char const *argv[])
{
    cin >> n >> m >> xa >> ya >> xb >> yb;
    int tmp = abs(xa - xb) + abs(ya - yb);
    if (tmp % 2) cout -1; else cout << tmp / 2;
    return 0;
}