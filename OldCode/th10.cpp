#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp = 2;
    while (n > 1)
    {
        while (n % temp == 0)
        {
            n /= temp;
            cout << temp;
            if (n > 1) cout << "*";
        }
        temp++;
    }
    return 0;
}
