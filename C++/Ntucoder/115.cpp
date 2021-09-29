
#include <iostream>

using namespace std;

int x, y, n = 8, a[10], ok;
char ans[10][10];

bool check(int xi, int yi){
    for (int i = 1; i < xi; i++)
        if ((a[i] == yi || abs(a[i] - yi) == abs(i - xi))) return 0;
    return 1;
}

void back(int i){
    if (ok) return;
    for (int j = 1; j <= 8; j++){
        if (check(i,j)){
            a[i] = j;
            if (i == 8){
                if (a[x] == y){
                    ok = 1;
                    for (int k = 1; k <= 8; k++){
                        for (int v = 1; v <= 8; v++){
                            if (a[k] == v) cout << "w";
                            else cout << ".";
                        }
                        cout << "\n";
                    }
                }
            }
            else back(i + 1);
        }
    }
}

int main(){
    cin >> x >> y;
    back(1);
    return 0;
}