#include <iostream>

using namespace std;

int main()
{
    for (int i = 2; i <= 9; i++)
    {
        cout << "Bang cuu chuong: " << i << endl;
        for (int j = 1; j <= 10; j++)
        {
            cout << i << " * " << j << " = " << i * j << endl;
        }
    }
    return 0;
}
