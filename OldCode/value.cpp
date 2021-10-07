#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string s ,x = "";
int c, n;

int main()
{
    static int a, b;
    static long long ans, res, B;
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            for (int j = i + 1; j < n; j++)
                if (s[j] == 'b') ans++;
        if (s[i] != 'a' && s[i] != 'b') res++;
    }
    //if (ans > c)
    {
        cout << c + 1 + res;
    }
    return 0;
}
