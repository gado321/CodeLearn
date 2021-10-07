#include <iostream>
#define FOR(i, a, b) for (int i = a; i<= b; i++)
using namespace std;

int main()
{
    FOR(i, 1, 999)
        FOR(j, 1, 999)
            FOR(l, 1, 999)
                if (i + j + l == i * j * l) cout << i << " " << j << " " << l << endl;
                else if (i + j + l <= i * j * l) break;
    return 0;
}
