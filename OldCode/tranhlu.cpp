#include <bits/stdc++.h>

using namespace std;

const int N = 55;

typedef pair <int,int> ii;

queue <ii> q;
int x[] = {0,  0, 1, -1};
int y[] = {1, -1, 0, 0};
int n, m, xd, yd, xc, yc, xs, ys, d[N][N], wd[N][N];
char a[N][N], w[N][N];
int ok[N][N];

void bfs2()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
		{
			w[i][j] = a[i][j];
			if (w[i][j] == '*') q.push(ii(i,j));
		}
	while (!q.empty())
	{
		ii u = q.front();
		q.pop();
		for (int i = 0; i <= 3; i++)
		{
			int xx = u.first + x[i];
			int yy = u.second + y[i];
			if (!ok[xx][yy] && xx && yy && xx <= n && yy <= m && w[xx][yy] != 'D')
			{
				w[xx][yy] = w[u.first][u.second];
				wd[xx][yy] = wd[u.first][u.second] + 1;
				ok[xx][yy] = 1;
				q.push(ii(xx,yy));
			}
		}
	}
}

void bfs(int xa,int ya)
{
	ok[xa][ya] = 1;
	q.push(ii(xa,ya));
	while (!q.empty())
	{
		ii u = q.front();
		q.pop();
		for (int i = 0; i <= 3; i++)
		{
			int xx = u.first + x[i];
			int yy = u.second + y[i];
			if ((!ok[xx][yy] && xx && yy && xx <= n && yy <= m) && (wd[xx][yy] > d[u.first][u.second] + 1 || w[xx][yy] == 'D'))
			{
				d[xx][yy] = d[u.first][u.second] + 1;
				ok[xx][yy] = 1;
				q.push(ii(xx,yy));
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("input.inp","r",stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '*') ok[i][j] = 1, xs = i, ys = j;
			if (a[i][j] == 'X') ok[i][j] = 2;
			if (a[i][j] == 'S') xd = i, yd = j;
			if (a[i][j] == 'D') xc = i, yc = j;
		}
	bfs2();
	memset(ok,0,sizeof(ok));
	bfs(xd,yd);
	for (int i = 1; i <= n; i++)
		
	return 0;
}