#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int n, tmp = 0;
long long ans = 0;
vector <bool> is_prime((int)1e10 + 5);

bool check(long long x)
{
    if (is_prime[x] == true) return true;
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;
    is_prime[x] = true;
    return true;
}

void backtrack(int i)
{
    for (int j = 1; j <= 9; j++)
    {
        ans = ans * 10 + j;
        tmp++;
        if (check(ans))
        {
            if (tmp == n) cout << ans << "\n";
            else backtrack(i + 1);
            ans /= 10;
            tmp--;
        }
        else
        {
            ans /= 10;
            tmp--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("bai40.inp","r",stdin);
    cin >> n;
    backtrack(1);
    return 0;
}
