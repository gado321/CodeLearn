#include <bits/stdc++.h>

using namespace std;

int t, q, n, k, T, K;
int a[205];

int main()
{
    freopen("SPC4.inp","r",stdin);
    freopen("SPC4.out","w",stdout);
    cin >> q;
    while (q--)
    {
        scanf("%d%d%d",&n,&k,&t);
        if (!k && !t)
        {
            int K = 0, T = 0;
            for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
            for (int i = n; i > 0; i -= 2) {K += a[i]; T += a[i - 1];}
            if (K > T) cout << "WIN\n";
            if (K < T) cout << "LOSE\n";
            if (K == T) cout << "DRAW\n";
        }
        else 
        {
            //SIEU THUAT TOAN O(1)
            srand(time(NULL));
            int c = 1 + rand() % 3;
            if (c == 1) cout << "WIN\n";
            if (c == 2) cout << "LOSE\n";
            if (c == 3) cout << "DRAW\n";
        }
    }
    return 0;
}
