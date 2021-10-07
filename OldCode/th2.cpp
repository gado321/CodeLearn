#include <iostream>

using namespace std;

int main()
{
    int n;
    static long long sum;
    cin >> n;
    for (int i = 1; i <= n; i++) sum += (i * i * i);
    cout << sum;

}
