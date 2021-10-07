#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

string s;
char x[200];
int n;

int main()
{
    cin >> n;
    int tmp = 2;
    while (n > 1)
    {
        if (n % tmp == 0)
        {
            cout << tmp << "*";
            n /= tmp;
        }
        else tmp++;
    }
}
