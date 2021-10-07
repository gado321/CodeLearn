#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long ll;

vector<int> adj[100000];
bool vis[100000];
int n;

int dfs(int v){
	vis[v] = true;

	int res = 1;
	for (int i = 0; i < adj[v].size(); i++)
		if(!vis[adj[v][i]])
			res+= dfs(adj[v][i]);

	return res;
}

int main() {
	ll n, k, v1, v2;
	freopen("daydx.inp","r",stdin);
  	freopen("daydx.out","w",stdout);
	cin >> n >> k;
	//Set Graph
	memset(vis, false, n);
	for (int i = 0; i < k; i++){
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	ll res = 0, temp;
	for (int i = 0; i < n; i++)
		if(!vis[i]){
			temp = dfs(i);
			cout << temp << " ";
			res += temp * (n-temp);
		}

	//cout << res/2;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}