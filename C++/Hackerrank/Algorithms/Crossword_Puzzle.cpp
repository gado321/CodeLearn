#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,ii> iii;

char q[11][11];
iii arrPos[1000];
string ch, s[50];
int n = 1, m, ok[1000], ok2[1000];

void findPos() {
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            // DI XUONG
            if (q[i][j] == '-' && q[i - 1][j] == '+' && q[i + 1][j] == '-') {
                int i1 = i;
                while (q[i1][j] == '-') i1++;
                arrPos[++m] = iii(ii(i,j),ii(i1 - 1,j));
            }
            // DI NGANG
            if (q[i][j] == '-' && q[i][j - 1] == '+' && q[i][j + 1] == '-') {
                int j1 = j;
                while (q[i][j1] == '-') j1++;
                arrPos[++m] = iii(ii(i,j),ii(i,j1 - 1));
            }
        }
}

int strSize(iii num) {
    return (abs(num.fi.fi - num.se.fi) + abs(num.fi.se - num.se.se) + 1);
}

int updateArr(iii poss, string st2) {
    if (poss.fi.fi == poss.se.fi) {
        //DI NGANG
        int tmp = 0;

        for (int i = poss.fi.se; i <= poss.se.se; i++) {
            if (q[poss.fi.fi][i] == '-') {
                q[poss.fi.fi][i] = st2[tmp];
            }
            else if (q[poss.fi.fi][i] != st2[tmp]) {

                for (int j = poss.fi.se; j < i; j++) q[poss.fi.fi][j] = '-';
                return 0;
            }
            tmp++;
        }
    }
    else if (poss.fi.se == poss.se.se) {
        //DI DOC
        int tmp = 0;
        for (int i = poss.fi.fi; i <= poss.se.fi; i++) {
            if (q[i][poss.fi.se] == '-') {
                q[i][poss.fi.se] = st2[tmp];
            }
            else if (q[i][poss.fi.se] != st2[tmp]) {
                for (int j = poss.fi.fi; j < i; j++) q[j][poss.fi.se] = '-';
                return 0;
            }
            tmp++;
        }
    }
    return 1;
}

void clearArr(iii poss) {
    if (poss.fi.fi == poss.se.fi) {
        //DI NGANG
        for (int i = poss.fi.se; i <= poss.se.se; i++) q[poss.fi.fi][i] = '-';
    }
    else if (poss.fi.se == poss.se.se) {
        //DI DOC
        for (int i = poss.fi.fi; i <= poss.se.fi; i++) q[i][poss.fi.se] = '-';
    }
}

void solve(int num) {
    if (num > m) return;
    for (int i = 1; i <= n; i++) {
        if (!ok[i] && strSize(arrPos[num]) == s[i].size()) {
            int tmp = updateArr(arrPos[num],s[i]);
            if (tmp == 1) {
                ok[i] = 1;
                if (num == m) {
                    for (int i = 1; i <= 10; i++) {
                        for (int j = 1; j <= 10; j++) cout << q[i][j];
                        cout << "\n";
                    }
                }
                solve(num + 1);
                ok[i] = 0;
                clearArr(arrPos[num]);
            }
        }
    }
}

int main() {
    memset(q,'+',sizeof(q));
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) cin >> q[i][j];
    cin >> ch;
    for (int i = 0; i < ch.size(); i++) {
        if (ch[i] != ';') s[n] += ch[i];
        else n++;
    }
    findPos();
    solve(1);
    return 0;
}
