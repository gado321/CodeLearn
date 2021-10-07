#include <iostream>

using namespace std;

int n, a[11], check[11], k, sum = 0, Count = 0;

void backtrack(int i)
{
    for (int j = 1; j <= k + 1; j++)
        if (check[i] == 0)
        {
            check[i] = 1;
            Count += a[i];
            if Count == a[i]
            if (i == n)

            else backtrack(i + 1);
            tmp[j]--;
        }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {cin >> a[i]; sum += a[i];}
    if (sum % k == 0)
    {
        sum /= k;
        backtrack(1);
    }
    return 0;
}
