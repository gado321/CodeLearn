#include <iostream>

using namespace std;

int main()
{
    int n;
    float sum = 1;
    cin >> n;
    for (int i = 2; i <= n; i++) sum += (1 / (float) i);
    cout << sum;
    return 0;
}
