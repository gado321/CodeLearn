#include <bits/stdc++.h>

using namespace std;

string s; char b[3];
int n;

void quay(int i)
{
    for (int j = 1; j <= 3; j++){
            s += b[j];
            if (s.length() == n){
                cout << s << endl;
            }
            else quay(i + 1);
            //s.erase(s.length(),1);
    }
}
int main()
{
    cin >> n;
    b[1] = 'A'; b[2] = 'B'; b[3] = 'C';
    //for (int i = 1; i<= n; i++) a[i] = "";
    s = "";
    quay(1);
    return 0;
}
