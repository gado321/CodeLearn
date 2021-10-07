#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

const int N = 1000000;

int check[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i<= n; i++) check[i] = 1;
    check[1] = 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (check[i] == 1)
            for (int j = i * i; j <= n; j += i) check[j] = 0;
    for (int i = 2; i <= n; i++)
        if (check[i] == 1) cout << i << " ";
    return 0;
}
