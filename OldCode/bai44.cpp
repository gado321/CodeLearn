#include <bits/stdc++.h>

using namespace std;

int n;
string s, a[2];

void quay(int i)
{
    for (int j = 1; j <= 2; j++ )
    {
        s += a[j];
        if (i == n)
        {
            int n = s.find("BB");
            if (n < 0) cout << s << endl;
        }
        else quay(i + 1);
        s.erase(s.length() - 1, 1);
    }
}
int main()
{
    freopen("bai44.inp","r",stdin);
    //freopen("bai44.out","w",stdout);
    cin >> n;
    s = "";
    a[1] = "A"; a[2] = "B";
    quay(1);
    return 0;
}
