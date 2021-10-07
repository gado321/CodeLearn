#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define maxn 1002
#define nd second
#define st first

using namespace std;
int n,m,s,t,u,v;
int tx[]={1,-1,1,-1};
int ty[]={1,-1,-1,1};
int a[maxn][maxn],l[maxn][maxn];
void solve()
{
    queue<pair<int,int> > q;
    q.push({s,t});
    while (q.size())
    {
        int x=q.front().st,y=q.front().nd;
        q.pop();
        fto(i,0,3)
        {
            int xx=x+tx[i],yy=y+ty[i];
            while (xx>0 && yy>0 && xx<=n && yy<=n && a[xx][yy]!=-1 && l[xx][yy]==INT_MAX)
            {
                l[xx][yy]=l[x][y]+1;
                if (xx==u && yy==v) {cout << l[u][v];return;}
                q.push({xx,yy});
                xx+=tx[i];yy+=ty[i];
            }
        }
    }
    cout << -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    //freopen("qt.inp", "r", stdin);
    //freopen("qt.out", "w", stdout);
    cin >> n >> m >> s >> t >> u >> v;
    fto(i,1,n)
    fto(j,1,n) l[i][j]=INT_MAX;
    l[s][t]=0;
    int x,y;
    fto(i,1,m) cin >> x >> y, a[x][y]=-1;
    solve();
    return 0;
}
    