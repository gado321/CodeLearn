#include <bits/stdc++.h>

using namespace std;

int m;
vector <int> a,b;

void oper(int m, int k)
{
    if (!m) return;
    if (m % 3 == 1) {m--; b.push_back(k);}
    else if (m % 3 == 2) {m++; a.push_back(k);}
    oper(m / 3,k * 3);
}

int main(int argc, char const *argv[])
{
    freopen("can3.inp","r",stdin);
    freopen("can3.out","w",stdout);
    cin >> m;
    oper(m,1);
    cout << a.size() << " ";
    for(int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << endl;
    cout << b.size() << " ";
    for(int i = 0; i < b.size(); i++) cout << b[i] << " "; cout << endl;
    return 0;
}
