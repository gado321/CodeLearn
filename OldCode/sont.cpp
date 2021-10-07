#include <iostream>

using namespace std;

int main()
{
    int a, cnt = 0;
    bool kt;
    cin >> a;
    for (int so = 1; so <= a; so++)
    {
        kt = true;
        if (so == 1 || so == 0) kt = false;
        else
        {
            for (int i = 2; i <= so - 1; i++)
                if (so % i == 0) kt = false;
            if (kt == true) cout << so << " ";
        }
    }
    return 0;
}
