#include <iostream>

using namespace std;

int row[10][10], column[10][10], a[10][10], area[4][4][10];

void back(int i, int j){
    if (i < 10 && j < 10){
        if (!a[i][j]){
            for (int k = 1; k <= 9; k++){
                if (!row[i][k] && !column[j][k] && !area[(i - 1) / 3][(j - 1) / 3][k]){
                    a[i][j] = k;
                    row[i][k] = 1;
                    column[j][k] = 1;
                    area[(i - 1) / 3][(j - 1) / 3][k] = 1;
                    back(i, j + 1);
                    a[i][j] = 0;
                    row[i][k] = 0;
                    column[j][k] = 0;
                    area[(i - 1) / 3][(j - 1) / 3][k] = 0;
                }
            }
        }
        else back(i, j + 1);
    }
    else if (i < 10 && j >= 10) back(i + 1, 1);
    else{
        for (int i = 1; i <= 9; i++){
            for (int j = 1; j <= 9; j++) cout << a[i][j] << " ";
            cout << endl;
        }
        exit(0);
    }
}

int main(){
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++){
            cin >> a[i][j];
            row[i][a[i][j]] = 1;
            column[j][a[i][j]] = 1;
            area[(i - 1) / 3][(j - 1) / 3][a[i][j]] = 1;
        }
    back(1,1);
    return 0;
}