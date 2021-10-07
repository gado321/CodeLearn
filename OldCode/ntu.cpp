#include <bits/stdc++.h>

using namespace std;

int a[9][9];
int e, b, c, d;

int main()
{
    cin >> b >> c >> d >> e;
    --b; --c; --d; --e;
    memset(a, 8 * 8, 0);
    static int dem;
    for (int i = 0; i < 8; i++)
    {
        if (a[i][c] == 0) a[i][c] = 1;
        if (a[b][i] == 0) a[b][i] = 1;
    }
    int i, j;
    if (d < e)
    {
        i = 0;
        j = max(d,e) - min(d,e);
    }
    else
    {
        j = 0;
        i = max(d,e) - min(d,e);
    }
    while (i < 8 && j < 8)
    {
        if (a[i][j] == 0) a[i][j] = 1;
        i++; j++;
    }
    /*i = 7;
    j = e - 7 + d;
    while (j < 8)
    {
        if (a[i][j] == 0) a[i][j] = 1;
        j++; i--;
    }*/
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++){
            if (a[i][j] == 1) dem++;
            cout << a[i][j] << " ";}
        cout << endl;
    }
    cout << dem;
    return 0;
}
