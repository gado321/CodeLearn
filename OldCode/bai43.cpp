#include <bits/stdc++.h>

using namespace std;

string s, x;
int a[11];

void quayvongvong(int i)
{
    for (int j = 1; j <= s.length(); j++)
    {
        if (a[j] == 0)
        {
            a[j] = 1;
            x += s[j - 1];
            if (i == s.length()) cout << x << endl;
            else quayvongvong(i + 1);
            a[j] = 0;
            x.erase(x.length() - 1, 1);
        }
    }
}
int main()
{
    //freopen("BAI43.inp","r",stdin);
    //freopen("BAI43.out","w",stdout);
    cin >> s;
    x = "";
    memset(a,0,11);
    quayvongvong(1);
    return 0;
}
