#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long f[40];
string res[40];
int n = 0;

int tim(int i, int j, int x)
{
    int l = i, r = j;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (f[mid] == x) return mid;
        else if (f[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return - 1;
}

void separate(int n)
{
    string kq = "";
    do
    {
        int z, x = 1, y = 0;
        {do
        {
            z = x + y;
            x = y;
            y = z;
        }
        while (z <= n);}
        string temp = res[tim(1,39,x) - 1];
        n -= x;
        if (kq == "") kq += temp;
        else kq[kq.length() - temp.length()] = temp[0];
    }
    while (n != 0);
    cout << kq << "\n";
}

int main()
{
    freopen("test.inp","r",stdin);
    f[0] = 0;
    f[1] = 1; res[1] = "1";
    for (int i = 2; i <= 39; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        res[i] = res[i - 1] + "0";
    }
    //while (1)
    {
        cin >> n;
        //if (n == -1) break;
        separate(n);
    }
    return 0;
}


