#include <bits/stdc++.h>
const int rx[4] = {-1, 0, 1, 0};
const int cx[4] = {0, 1, 0, -1};
using namespace std;

struct cell{
    int r, c, cnt;
    cell(int _r, int _c,  int _cnt){
        r = _r, c = _c, cnt = _cnt;
    }
};

int n, k,r0,c0,r1,c1;
int a[105][105];
queue<cell> Q;

int BFS(){
    Q.push(cell(r0,c0,0));
    a[r0][c0] = -1;
    while(!Q.empty()){
        int r = Q.front().r;
        int c = Q.front().c;
        int cnt = Q.front().cnt;
        Q.pop();
        if(r == r1 && c == c1) return cnt;
        for(int k = 0; k < 4; k++){
            for(int j = 1; a[r + j*rx[k]][c + j*cx[k]] == 0; j++){
                a[r + j*rx[k]][c + j*cx[k]] = -1;
                Q.push(cell(r + j*rx[k], c + j*cx[k], cnt + 1));
            }
        }
    }
    return -1;
}

int main() {
    //ifstream cin("x.inp");
    cin >> n;
    memset(a,-1,sizeof(a));
    string s;
    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++)
            if(s[j] == '.') a[i][j+1] = 0;
    }
    cin >> r0 >> c0 >> r1 >> c1;
    r0++, c0++, r1++, c1++;
    cout << BFS()<< endl;
    return 0;
}
