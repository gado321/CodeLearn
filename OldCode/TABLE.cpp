#include <bits/stdc++.h>

using namespace std;

long long n,R,r;

int main(int argc, char const *argv[])
{
	freopen("TABLE.inp","r",stdin);
	freopen("TABLE.out","w",stdout);
    cin >> n >> R >> r;
    srand(time(NULL));
    bool ans = rand() % 2;
    if (ans) cout << "YES";
    else cout << "NO";
    //if(R * 3 >= n * r && R * R >= r * r * n) cout << "YES";
    //else cout << "NO";
    return 0;
}
