#include <iostream>
#include <limits.h>

using namespace std;

int a[10][10], sumMax = INT_MIN;

int calSum(int r, int c) {
    int s = 0;
    for (int i = r; i <= r + 2; i++)
        for (int j = c; j <= c + 2; j++) s += a[i][j];
    s -= a[r + 1][c]; s -= a[r + 1][c + 2];
    return s;
}

int main() {
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++) cin >> a[i][j];
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++) sumMax = max(sumMax,calSum(i,j));
    cout << sumMax;
    return 0;
}