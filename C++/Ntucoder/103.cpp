#include <iostream>

using namespace std;

int a[30], n;

void back(int k) {
    for (int i = 0; i <= 1; i++) {
        a[k] = i;
        if (k == n) {
            for (int j = 1; j <= n; j++) cout << a[j];
            cout << "\n";
        }
        else back(k + 1);
    }
}

int main() {
    cin >> n;
    back(1);
    return 0;
}