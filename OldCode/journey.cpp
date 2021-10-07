#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100005];
int n, m, cnt = 0;
bool check[100005];
long long ans = 0;

void dfs(int u)
{
  cnt++;
  check[u] = 1;
  for (int i = 0; i < adj[u].size(); i++)
  {
    int v = adj[u][i];
    if (!check[v]) dfs(v);
  }
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  //freopen("daydx.inp","r",stdin);
  //freopen("daydx.out","w",stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++)
    if (!check[i]) 
    {
      cnt = 0; 
      dfs(i);
      ans += cnt * (n - cnt);
    }
  cout << ans / 2;
  return 0;
}