#include <bits/stdc++.h>

using namespace std;

string s;
bool check[2000];
static int sjze;

int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        int tmp = 0;
        memset(check,0,sizeof(check));
        for (int j = i; j < s.size(); j++)
            if (check[s[j]] == 0) {check[s[j]] = 1; tmp++;}
        else break;
        sjze = max(sjze,tmp);
    }
    cout << sjze;
    return 0;
}
