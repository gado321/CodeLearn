#include <bits/stdc++.h>

using namespace std;

string s[50];

int main() {
    s[0] = 'a';
    s[1] = 'b';
    for (int i = 2; i <= 40; i++) s[i] = s[i - 1] + s[i - 2];
    cout << s[40];
    return 0;
}
