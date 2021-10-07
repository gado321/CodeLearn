#include <bits/stdc++.h>

using namespace std;

int vt, n, mo, dong;
char a[2];
string s, x;

void quay(int i)
{
    for (int j = 1; j <= 2; j++)
    {
        s += a[j];
        if (a[j] == ')') dong++;
        if (a[j] == '(') mo++;
        if (i == n * 2)
        {
            if (dong == mo && s[0] != ')' && s[s.length() - 1] != '(')
            {
                x = s;
                vt = x.find("()");
                while (vt >= 0)
                {
                    x.erase(vt,2);
                    vt = x.find("()");
                }
                if (x.length() == 0 ) cout << s << endl;
            }
        }
        else quay(i + 1);
        s.erase(s.length() - 1, 1);
        if (a[j] == ')') dong--;
        if (a[j] == '(') mo--;
    }
}

int main()
{
    freopen("BAI47.inp","r",stdin);
    freopen("BAI47.out","w",stdout);
    cin >> n;
    a[1] = '('; a[2] = ')';
    s = "";
    dong = 0; mo = 0;
    quay(1);
    return 0;
}
