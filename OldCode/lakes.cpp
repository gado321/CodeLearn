#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
bool a[51][51]={};
int n, m, k;
int b[300];
int l = 1;
int res = 0;
void dfs2 (int x, int y)
{

    if (a[x][y] == 0) return;
    a[x][y] = 0;
    res++;
    dfs2(x+1,y);
    dfs2(x-1,y);
    dfs2(x,y-1);
    dfs2(x,y+1);
}
void dfs1(int x, int y)
{
    if (x <= 0 || y <= 0 || x > n || y > m) return;
    if (a[x][y] == 0) return;
    a[x][y] =0;
    dfs1(x+1,y);
    dfs1(x-1,y);
    dfs1(x,y+1);
    dfs1(x,y-1);
}
void output ()
{
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main ()
{
    freopen("LAKES.INP", "r", stdin);
    freopen("LAKES.OUT", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char x;
            cin >> x;
            if(x=='*') a[i][j]=0;
            else a[i][j]=1;
        }
    }
    for (int i = 1; i <= n; i++){
        dfs1(i,1);
        dfs1(i,m);
    }
    for (int i = 1; i <= m; i++){
        dfs1(1,i);
        dfs1(n,i);
    }
    //output();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            res = 0;
            dfs2(i,j);
            if (res){
                b[l] = res;;
                l++;
            }
        }
    }
    //for (int i = 1; i < l; i++) cout << b[i] << " ";
    sort(b + 1,b + (l-1) + 1);
    //cout << endl;
    //for (int i = 1; i < l; i++) cout << b[i] << " ";
    //cout << endl;
    int sum = 0;
    for (int i = 1; i <= l-1-k; i++){
        sum += b[i];
    }
    cout << sum;
    return 0;
}