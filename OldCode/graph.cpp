#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

int a[1000], b[1000], adj[1000], head[1000], n, m;

int main()
{
    freopen("graph.inp","r",stdin);
    cin >> n >> m;
    memset(head,0,n + 2);
    FOR(i,1,m)
    {
        cin >> a[i] >> b[i];
        head[a[i]]++;
        //head[b[i]]++;
    }
    FOR(i,2,n + 1) head[i] = head[i - 1] + head[i];
    FOR(i,1,m)
    {
        adj[head[a[i]]] = b[i];
        head[i]--;
    }
    /*for (int i = 1; i <= n; i++){
        for (int j = head[i] + 1; j <= head[i + 1]; j++) cout << adj[j] << " ";
        cout << endl;}
    */
    for (int i = 1; i <= 10; i++) cout << adj[i] << " ";
    return 0;
}
