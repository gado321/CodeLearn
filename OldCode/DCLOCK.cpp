#include <iostream>

using namespace std;

int main()
{
    static int h, m, dem;
    cin >> h >> m;
    for (int i = 0; i <= 23; i++)
        for (int j = 0; j <= 59; j++)
        {
            if (i < 10 && j < 10 && i == j && i <= h && j <= m) dem++;
            else if (i < 10 && j >= 10 && i == j / 10 && j / 10 == j % 10 && i <= h && j <= m) dem++;
            else if (j < 10 && i >= 10 && j == i / 10 && i / 10 == i % 10 && i <= h && j <= m) dem++;
            else if (i >= 10 && j >= 10 && i == j && i / 10 == i % 10 && j / 10 == j % 10 && i <= h && j <= m) dem++;
        }
    cout << dem;
    return 0;
}
