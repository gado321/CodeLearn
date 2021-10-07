#include <bits/stdc++.h>

using namespace std;

int a[1000], n;
bool check[1000];
void quay(int i)
{
    for (int j = 1; j <= n; j++)
        if (check[j] == true)
        {
            a[i] = j;
            check[j] = false;
            if (i == n)
            {
                for (int l = 1; l <= n; l++) cout << a[l] << " ";
                cout << endl;
            }
            else quay(i + 1);
            check[j] = true;
        }
}

int main()
{
    cin >> n;
    memset(check, 1, 1000);
    quay(1);
    return 0;
}
