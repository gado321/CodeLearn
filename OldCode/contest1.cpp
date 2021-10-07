#include <iostream>
#include <cstring>
#define FOR(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

const int N = 2 * (int) 1e6;

int n, a[N], dpfake[N], check[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    memset(check, 0, N + 5);
    FOR(i, 1, n)
    {
        int pos_i = a[i] + 1;
        if (pos_i > n)
        //while (pos_i > n)
        {
            dpfake[i] = pos_i - n;
            //pos
            check[i]++;
        }
        else dpfake[i] = pos_i;
    }
    int temp = N + 5, res;
    /*FOR(i, 1, n)
        if (temp > dpfake[i])
        {
            temp = dpfake[i];
            res = i;
        }

    cout << res;*/
    FOR(i, 1, n) cout << check[i] << " "; cout << endl;
    FOR(i, 1, n) cout << dpfake[i] << " ";
    return 0;
}
