#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair <int,int> ii;
typedef pair <ii,int> iii;

int xx[] = {0,  0, 1, -1, 1, -1, -1,  1};
int yy[] = {1, -1, 0,  0, 1, -1,  1, -1};

int x, y, n, m, cp, k, kk;
char s[105][105];
int a[105][105], b[100000], tmp[100000];
bool ok[105][105];
queue <ii> q;

void bfs(int x1, int y1,int h)
{
	ok[x1][y1] = 1;
	q.push(ii(x1,y1));
	while (!q.empty())
	{
		ii u = q.front();
		q.pop();
		for (int i = 0; i < 7; i++)
		{
			int xa = u.fi + xx[i];
			int ya = u.se + yy[i];
			if (!ok[xa][ya] && )
			{

			}
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("quanoel.inp","r",stdin);
	//freopen("quanoel.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> s[i][j];
			if (s[i][j] == 'P') {x = i; y = j;}
			if (s[i][j] == 'K') cp++;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {cin >> a[i][j]; tmp[++kk] = a[i][j];}
	sort(tmp + 1, tmp + kk + 1);
	for (int i = 1; i <= kk; i++)
		if (tmp[i] != tmp[i - 1]) {b[++k] = tmp[i];}
	return 0;
}