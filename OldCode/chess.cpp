#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
#include <string>

#define fi first
#define se second

using namespace std;

const int N = 300;

typedef pair <int,int> ii;
typedef pair <ii,int> iii;

int a[N][N];
int n, m, bottom, d[N][N];
int x[] = {0, -1, -1};
int y[] = {1, 0, 1};
bool ok[N][N];
queue <iii> q;

void bfs()
{
    ok[n][1] = 1;
    q.push(iii(ii(n,1),0));
    while (!q.empty())
    {
        iii u = q.front();
        q.pop();
        for (int k = 0; k < 3; k++)
        {
            int xx = u.fi.fi + x[k];
            int yy = u.fi.se + y[k];
            int dis = u.se + 1;
            int color = a[xx][yy];
            if (!ok[xx][yy] && xx && yy && xx <= n && yy <= m)
                if (((dis % 2) && color != bottom) || (!(dis % 2) && color == bottom))
                {
                    d[xx][yy] = d[u.fi.fi][u.fi.se] + 1;
                    q.push(iii(ii(xx,yy),dis));
                    ok[xx][yy] = 1;
                }
        }
    }
}

int main()
{
    //freopen("chess.inp","r",stdin);
    //freopen("chess.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char s; cin >> s;
            if (s == 'G') a[i][j] = 1;
            else a[i][j] = 0;
        }
    bottom = a[n][1];
    bfs();
    if (d[1][m]) cout << "TRUE"; else cout << "FALSE";
    return 0;
}
