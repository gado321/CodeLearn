#include <bits/stdc++.h>

using namespace std;

vector <int> adj[3];
int n, dem = 0;
bool ok[100005];

void dfs(int u)
{
    dem++;
    for (int v = 1; v <= sqrt(u); v++)
        if (u % v == 0)
        {
            int x;
            x = (v - 1) * (u / v + 1);
            if (ok[x] == 0) ok[x] = 1, dfs(x);
        }
}

int main()
{
    cin >> n;
    dfs(n);
    cout << --dem << "\n";
    for (int i = 0; i <= n; i++)
        if (ok[i]) cout << i << " ";
}
