#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

 using namespace std;

 int n;
 char a[100001];
 int b[100001];
 int c[100001];

 int main()
 {
    //freopen("a.inp","r",stdin);
    cin >> n;
    int l = 1;
    c[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == '?') {b[i] = 0; c[l] = i; l++;}
        else cin >> b[i];
    }
    b[0] = 0;
    b[n + 1] = 1000000000;
    int x = n + 1, y = 0, res1, res2;
    res1 = -1000000000; res2 = 1000000000;
    for (int i = 1; i <= l - 1; i++)
    {
        for (int j = c[i - 1] + 1; j < c[i]; j++)
        {
            if (a[j] == '>' && b[j] >= res1) {y = j; res1 = b[j];}
            if (a[j] == '<' && b[j] <= res2) {x = j; res2 = b[j];}
        }
        if (abs(b[x] - b[y]) != 1 && b[x] > b[y])
            {if (b[x] - 1 >= 0) cout << b[x] - 1 << endl; else cout << -1 << endl;}
        else cout << -1 << endl;
    }
     return 0;
 }
