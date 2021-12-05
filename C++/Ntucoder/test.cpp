#include <iostream>

using namespace std;

float k, f, c;

int main() {
    cin >> f;
    c = (float) 5/9 * (f - 32);
    k = (float) 5/9 * (f - 32) + 273.15;
    cout << c << " " << k;
    return 0;
}