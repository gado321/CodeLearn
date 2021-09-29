#include <iostream>

using namespace std;

int x, y, a[50], b[50], ansmin[50], ansmax[50], n, m, kmin, kmax;

void cmin(int i, int j){
    while (i > 0 || j > 0){
        if (a[i] < b[j]){
            ansmin[++kmin] = a[i];
            i--;
        }
        else if (a[i] > b[j]){
            ansmin[++kmin] = b[j];
            j--;
        }
        else{
            int it = i, jt = j;
            while (a[i] == b[j] && (i || j)){
                i--;
                j--;
                if (a[i] <= a[i + 1] && a[i] == b[j]) {}
                else {
                    if (a[i] < b[j]){ 
                        for (int c = it; c > i; c--) ansmin[++kmin] = a[c];
                        j = jt;
                        it = i;

                    }
                    else{
                        for (int c = jt; c > j; c--) ansmin[++kmin] = b[c];
                        i = it;
                        jt = j;
                    }
                }
            }
        }
    }
}

void cmax(int i, int j){
    while (i > 0 || j > 0){
        if (a[i] > b[j]){
            ansmax[++kmax] = a[i];
            i--;
        }
        else if (a[i] < b[j]){
            ansmax[++kmax] = b[j];
            j--;
        }
        else{
            int it = i, jt = j;
            while (a[i] == b[j] && (i || j)){
                i--;
                j--;
                if (a[i] >= a[i + 1] && a[i] == b[j]) {}
                else{
                    if (a[i] > b[j]){
                        for (int c = it; c > i; c--) ansmax[++kmax] = a[c];
                        j = jt;
                        it = i;
                    }
                    else{
                        for (int c = jt; c > j; c--) ansmax[++kmax] = b[c];
                        i = it;
                        jt = j;
                    }
                }
            }
        }
    }
}

int main(){
    cin >> x >> y;
    while (x){
        a[++n] = x % 10;
        x /= 10;
    }
    int cnt = 0;
    while (y){
        b[++m] = y % 10;
        y /= 10;
    }
    a[0] = 10; b[0] = 10;
    cmin(n, m);
    a[0] = -10; b[0] = -10;
    cmax(n, m);
    for (int i = 1; i <= kmin; i++) cout << ansmin[i];
    cout << "\n";
    for (int i = 1; i <= kmax; i++) cout << ansmax[i];
    return 0;
}