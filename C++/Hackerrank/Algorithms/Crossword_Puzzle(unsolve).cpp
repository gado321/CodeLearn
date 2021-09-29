#include <bits/stdc++.h>

using namespace std;

char q[11][11];
string ch, s[50];
int n = 1;

void fill(int u, int v, int len, int direction) {
    int c = 0;
    if (direction == 1) {
        for (int i = v; i <= len; i++) 
            if (q[u][i] == '-') q[u][i] = s[c++];
            else 
    }
    else if (direction == 2) {
        for (int i = v; i <= len; i++)
            q[u][i] = s[c++];
    }
} 

void back(int u, int v) {
    for (int i = u; i <= 10; i++)
        for (int j = v; j <= 10; j++) {
            if (q[i][j] != '+') {
                
            }
        }
}

int main() {
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) cin >> q[i][j];
    cin >> ch;
    for (int i = 0; i < ch.size(); i++) {
        if (ch[i] != ';') s[n] += ch[i];
        else n++;
    } 
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << s[i] << endl;
    return 0;
}