#include <iostream>

using namespace std;

int a1, a2, b1, b2;

int main()
{
    cin >> a1 >> b1 >> b2 >> a2;
    if (a1 + a2 < b1 + b2) cout << "B wins";
    else if (a1 + a2 > b1 + b2) cout << "A wins";
    else if (a1 + a2 == b1 + b2)
    {
        if (b1 > a2) cout << "B wins";
        else if (b1 < a2) cout << "A wins";
        else if (b1 == a2) cout << "Extra time";
    }
    return 0;
}
