#include <iostream>
#include <fstream>

using namespace std;

int n, a[1005],b[1005], f[1005][1005];

void truyvet(int d, int c)
{
	if (d < 1 || c < 1) return;	
    if (a[d] == b[c])
    {
        truyvet(d - 1, c - 1);
        cout << a[d] << " ";
    }
    else
    {
        if ( f[d - 1][c] > f[d][c - 1]) truyvet(d - 1,c);
        if (f[d][c - 1] >= f[d - 1][c]) truyvet(d, c - 1);
    }
}

int main(int argc, char const *argv[])
{
	freopen("daydx.inp","r",stdin);
	freopen("daydx.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		b[n - i + 1] = a[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
			if (a[i] != b[j]) f[i][j] = max(f[i][j - 1],f[i - 1][j]);
		}
	/*for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) cout << f[i][j] << " ";
			cout << endl;
	}*/
	cout << f[n][n] << endl;
	truyvet(n,n);
	return 0;
}