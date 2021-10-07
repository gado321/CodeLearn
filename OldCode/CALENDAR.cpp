#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string so(int a, int b, int c)
{
    string s = "";
    for (int i = 1; i <= a; i++) s += "1";
    for (int i = 1; i <= b; i++) s += "0";
    for (int i = 1; i <= c; i++) s += "1";
    return s;
}

long long tinh(string s)
{
    long long dem = 1;
    for (int i = 1; i <= s.length() - 1; i++)
        if (s[i] == '0') dem = dem * 2; else dem = dem * 2 + 1;
    return dem;
}

int main()
{
    freopen("test.inp","r",stdin);
    long long a, b, dem = 0;
    int tam;
    cin >> a >> b;
    for (int i = 1; i <= 60; i++)
        for (int j = 1; j <= 60 - i; j++)
            for (int l = 1; l <= 60 - i - j; l++)
                if (tinh(so(i,j,l)) >= a && tinh(so(i,j,l)) <= b) dem++;
    cout << dem;
    return 0;
}
