#include <iostream>

using namespace std;

int n, k, a, b, c;

void HanoiTower(int num, int &a, int &b, int &c) {
    if (k == 0) return;
    if (num == 1) {
        a--; b++; k--;        
    }
    else {  
        HanoiTower(num - 1, a, c, b);
        HanoiTower(1, a, b, c);
        HanoiTower(num - 1, c, b, a);
    }
}

int main() {
    cin >> n >> k;
    a = n;
    HanoiTower(n,a,b,c);
    cout << a << " " << b << " " << c;
    return 0;
}